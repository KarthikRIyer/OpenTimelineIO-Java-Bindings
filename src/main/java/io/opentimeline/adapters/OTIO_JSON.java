package io.opentimeline.adapters;

import io.opentimeline.opentimelineio.ErrorStatus;
import io.opentimeline.opentimelineio.SerializableObject;

/**
 * This adapter lets you read and write native .otio files.
 */
public class OTIO_JSON {

    /**
     * De-serializes a SerializableObject from a file.
     *
     * @param filePath The path to an otio file to read from
     * @return A SerializableObject
     */
    public SerializableObject readFromFile(String filePath) {
        ErrorStatus errorStatus = new ErrorStatus();
        SerializableObject serializableObject = SerializableObject.fromJSONFile(filePath, errorStatus);
        try {
            errorStatus.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return serializableObject;
    }

    /**
     * De-serializes a SerializableObject from a JSON string.
     *
     * @param OTIOString A string containing json serialized otio contents
     * @return A SerializableObject
     */
    public SerializableObject readFromString(String OTIOString) {
        ErrorStatus errorStatus = new ErrorStatus();
        SerializableObject serializableObject = SerializableObject.fromJSONString(OTIOString, errorStatus);
        try {
            errorStatus.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return serializableObject;
    }

    /**
     * Serializes a SerializableObject into a string.
     *
     * @param serializableObject A SerializableObject
     * @return A JSON serialized string representation
     */
    public String writeToString(SerializableObject serializableObject) {
        ErrorStatus errorStatus = new ErrorStatus();
        String OTIOString = serializableObject.toJSONString(errorStatus);
        try {
            errorStatus.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return OTIOString;
    }

    /**
     * Serializes a SerializableObject into a string.
     *
     * @param serializableObject A SerializableObject
     * @param filePath           The name of an otio file to write to
     */
    public boolean writeToFile(SerializableObject serializableObject, String filePath) {
        ErrorStatus errorStatus = new ErrorStatus();
        boolean result = serializableObject.toJSONFile(filePath, errorStatus);
        try {
            errorStatus.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return result;
    }

}
