// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

package io.opentimeline;

import java.io.IOException;

import static io.opentimeline.OTIOFactory.OTIO_VERSION;

/**
 * This class uses NativeUtils to load native libraries from the JAR archive.
 * In case it is unable to load them from the JAR archive it falls back to try loading from the system.
 */
public class LibraryLoader {
    private static boolean libLoaded = false;

    private static String getOSName() {
        String osName = System.getProperty("os.name").toLowerCase();
        if (osName.contains("win")) return "Windows";
        else if (osName.contains("mac")) return "Darwin";
        else if (osName.contains("nux")) {
            if(System.getProperty("java.vm.name").toLowerCase().contains("dalvik"))
                return "Android";
            return "Linux";
        }
        return "";
    }

    public static void load(String name) {
        if (libLoaded)
            return;
        final String libname = System.mapLibraryName(name);
        final String opentimelibname = System.mapLibraryName("opentime");
        final String OTIOlibname = System.mapLibraryName("opentimelineio");
        final String platformName = getOSName();
        final String libPkgPath = "/" + platformName + "/" + libname;
        final String libOpentimePath = "/" + platformName + "/" + opentimelibname;
        final String libOTIOPath = "/" + platformName + "/" + OTIOlibname;
        try {
            NativeUtils.loadLibraryFromJar(libOpentimePath);
            NativeUtils.loadLibraryFromJar(libOTIOPath);
            NativeUtils.loadLibraryFromJar(libPkgPath);
            libLoaded = true;
        } catch (IllegalArgumentException | IOException e) {
            System.loadLibrary("opentime");
            System.loadLibrary("opentimelineio");
            System.loadLibrary(name);
            libLoaded = true;
        } catch (Exception e) {
            libLoaded = false;
            System.err.println("Unable to load native library.");
        }
    }
}
