package io.opentimeline;

import io.opentimeline.adapters.Adapter;
import io.opentimeline.adapters.AdapterManifest;
import io.opentimeline.opentimelineio.SerializableObject;

import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Adapters convert between OTIO and other formats.
 * <p>
 * Note that this class is not extended by adapters. Rather, an adapter is a class that implements at least
 * one of the following functions:
 * <p>
 * &emsp; public SerializableObject readFromFile(String filePath)
 * &emsp; public SerializableObject readFromString(String OTIOString)
 * &emsp; public String writeToString(SerializableObject serializableObject)
 * &emsp; public boolean writeToFile(SerializableObject serializableObject, String filePath)
 * <p>
 * The class <em>AdapterManifest</em> advertises the features of the adapter to OTIO.
 * This class serves as a wrapper around these functions, internal to OTIO.
 */
public class Adapters {

    public static SerializableObject readFromFile(String filePath) throws FileTypeNotSupportedException {
        int extensionIndex = filePath.lastIndexOf('.');
        String extension = (extensionIndex > 0) ? filePath.substring(extensionIndex + 1) : "";
        Adapter[] adapters = AdapterManifest.getAdaptersList();

        for (Adapter adapter : adapters) {
            if (Arrays.asList(adapter.suffixes()).contains(extension)) {
                ClassLoader classLoader = ClassLoader.getSystemClassLoader();
                String classNameToBeLoaded = "io.opentimeline.adapters." + adapter.classname();
                try {
                    Class<?> adapterClass = classLoader.loadClass(classNameToBeLoaded);
                    Method[] adapterMethods = adapterClass.getMethods();
                    List<String> adapterMethodNames = Arrays.stream(adapterMethods).map(Method::getName).collect(Collectors.toList());
                    int readFromStringIndex = adapterMethodNames.indexOf("readFromString");
                    int readFromFileIndex = adapterMethodNames.indexOf("readFromFile");
                    Object adapterInstance = adapterClass.newInstance();
                    if (readFromStringIndex != -1) {
                        Method readFromStringMethod = adapterMethods[readFromStringIndex];
                        String fileString = new String(Files.readAllBytes(Paths.get(filePath)));
                        return (SerializableObject) readFromStringMethod.invoke(adapterInstance, fileString);
                    } else if (readFromFileIndex != -1) {
                        Method readFromFileMethod = adapterMethods[readFromFileIndex];
                        return (SerializableObject) readFromFileMethod.invoke(adapterInstance, filePath);
                    }

                } catch (ClassNotFoundException | IllegalAccessException | InstantiationException |
                        InvocationTargetException | IOException e) {
                    e.printStackTrace();
                }
            }
        }
        throw new FileTypeNotSupportedException("File type '" + extension + "' is not supported.");
    }

    public static boolean writeToFile(SerializableObject inputOTIO, String filePath) throws FileTypeNotSupportedException {
        int extensionIndex = filePath.lastIndexOf('.');
        String extension = (extensionIndex > 0) ? filePath.substring(extensionIndex + 1) : "";
        Adapter[] adapters = AdapterManifest.getAdaptersList();

        for (Adapter adapter : adapters) {
            if (Arrays.asList(adapter.suffixes()).contains(extension)) {
                ClassLoader classLoader = ClassLoader.getSystemClassLoader();
                String classNameToBeLoaded = "io.opentimeline.adapters." + adapter.classname();
                try {
                    Class<?> adapterClass = classLoader.loadClass(classNameToBeLoaded);
                    Method[] adapterMethods = adapterClass.getMethods();
                    List<String> adapterMethodNames = Arrays.stream(adapterMethods).map(Method::getName).collect(Collectors.toList());
                    int writeToStringIndex = adapterMethodNames.indexOf("writeToString");
                    int writeToFileIndex = adapterMethodNames.indexOf("writeToFile");
                    Object adapterInstance = adapterClass.newInstance();
                    if (writeToStringIndex != -1) {
                        Method writeToStringMethod = adapterMethods[writeToStringIndex];
                        String OTIOString = (String) writeToStringMethod.invoke(adapterInstance, inputOTIO);
                        FileWriter fileWriter = new FileWriter(filePath);
                        fileWriter.write(OTIOString);
                        fileWriter.close();
                        return true;
                    } else if (writeToFileIndex != -1) {
                        Method writeToFileMethod = adapterMethods[writeToFileIndex];
                        return (boolean) writeToFileMethod.invoke(adapterInstance, inputOTIO, filePath);
                    }
                } catch (ClassNotFoundException | IllegalAccessException | InstantiationException |
                        InvocationTargetException | IOException e) {
                    e.printStackTrace();
                    return false;
                }
            }
        }
        throw new FileTypeNotSupportedException("File type '" + extension + "' is not supported.");
    }

}
