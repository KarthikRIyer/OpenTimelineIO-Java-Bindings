// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

#include <exceptions.h>
#include <handle.h>
#include <io_opentimeline_opentimelineio_Deserialization.h>
#include <opentimelineio/deserialization.h>
#include <opentimelineio/version.h>

using namespace opentimelineio::OPENTIMELINEIO_VERSION;

/*
 * Class:     io_opentimeline_opentimelineio_Deserialization
 * Method:    deserializeJSONFromString
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;Lio/opentimeline/opentimelineio/ErrorStatus;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_opentimeline_opentimelineio_Deserialization_deserializeJSONFromString
        (JNIEnv *env, jobject thisObj, jstring input, jobject anyDestination, jobject errorStatusObj) {
    if (anyDestination == nullptr || errorStatusObj == nullptr ||
        input == nullptr) {
        throwNullPointerException(env, "");
        return false;
    }
    std::string inputStr = env->GetStringUTFChars(input, nullptr);
    auto anyDestinationHandle =
            getHandle<any>(env, anyDestination);
    auto errorStatusHandle =
            getHandle<ErrorStatus>(env, errorStatusObj);
    return deserialize_json_from_string(
            inputStr, anyDestinationHandle, errorStatusHandle);
}

/*
 * Class:     io_opentimeline_opentimelineio_Deserialization
 * Method:    deserializeJSONFromFile
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;Lio/opentimeline/opentimelineio/ErrorStatus;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_opentimeline_opentimelineio_Deserialization_deserializeJSONFromFile
        (JNIEnv *env, jobject thisObj, jstring fileName, jobject anyDestination, jobject errorStatusObj) {
    if (anyDestination == nullptr || errorStatusObj == nullptr ||
        fileName == nullptr) {
        throwNullPointerException(env, "");
        return false;
    }
    std::string fileNameStr = env->GetStringUTFChars(fileName, nullptr);
    auto anyDestinationHandle =
            getHandle<any>(env, anyDestination);
    auto errorStatusHandle =
            getHandle<ErrorStatus>(env, errorStatusObj);
    return deserialize_json_from_string(
            fileNameStr, anyDestinationHandle, errorStatusHandle);
}
