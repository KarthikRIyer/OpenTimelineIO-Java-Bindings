// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

#include <exceptions.h>
#include <handle.h>
#include <io_opentimeline_opentimelineio_SerializableObject.h>
#include <opentimelineio/serializableObject.h>
#include <opentimelineio/version.h>
#include <utilities.h>

using namespace opentimelineio::OPENTIMELINEIO_VERSION;

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_initialize(
        JNIEnv *env, jobject thisObj) {
    auto serializableObject = new SerializableObject();
    auto serializableObjectManager =
            new SerializableObject::Retainer<SerializableObject>(serializableObject);
    setHandle(env, thisObj, serializableObjectManager);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    toJSONFile
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/ErrorStatus;)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_toJSONFile__Ljava_lang_String_2Lio_opentimeline_opentimelineio_ErrorStatus_2(
        JNIEnv *env, jobject thisObj, jstring fileNameStr, jobject errorStatusObj) {
    if (fileNameStr == nullptr || errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return false;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto serializableObject = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    return serializableObject->to_json_file(
            env->GetStringUTFChars(fileNameStr, 0), errorStatusHandle);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    toJSONFile
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/ErrorStatus;I)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_toJSONFile__Ljava_lang_String_2Lio_opentimeline_opentimelineio_ErrorStatus_2I(
        JNIEnv *env,
        jobject thisObj,
        jstring fileNameStr,
        jobject errorStatusObj,
        jint indent) {
    if (fileNameStr == nullptr || errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return false;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto serializableObject = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    return serializableObject->to_json_file(
            env->GetStringUTFChars(fileNameStr, 0), errorStatusHandle, indent);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    toJSONString
 * Signature: (Lio/opentimeline/opentimelineio/ErrorStatus;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_toJSONString__Lio_opentimeline_opentimelineio_ErrorStatus_2(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto serializableObject = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    return env->NewStringUTF(
            serializableObject->to_json_string(errorStatusHandle).c_str());
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    toJSONString
 * Signature: (Lio/opentimeline/opentimelineio/ErrorStatus;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_toJSONString__Lio_opentimeline_opentimelineio_ErrorStatus_2I(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj, jint indent) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto serializableObject = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    return env->NewStringUTF(
            serializableObject->to_json_string(errorStatusHandle, indent)
                    .c_str());
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    fromJSONFile
 * Signature:
 * (Ljava/lang/String;Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentimelineio/SerializableObject;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_fromJSONFile(
        JNIEnv *env, jclass thisClass, jstring fileNameStr, jobject errorStatusObj) {
    if (fileNameStr == nullptr || errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = SerializableObject::from_json_file(
            env->GetStringUTFChars(fileNameStr, 0), errorStatusHandle);
    return serializableObjectFromNative(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    fromJSONString
 * Signature:
 * (Ljava/lang/String;Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentimelineio/SerializableObject;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_fromJSONString(
        JNIEnv *env, jclass thisClass, jstring JSONStr, jobject errorStatusObj) {
    if (JSONStr == nullptr || errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = SerializableObject::from_json_string(
            env->GetStringUTFChars(JSONStr, 0), errorStatusHandle);
    return serializableObjectFromNative(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    isEquivalentTo
 * Signature: (Lio/opentimeline/opentimelineio/SerializableObject;)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_isEquivalentTo(
        JNIEnv *env, jobject thisObj, jobject otherObj) {
    if (otherObj == nullptr) {
        throwNullPointerException(env, "");
        return false;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    auto otherHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, otherObj);
    auto otherSerializableObject = otherHandle->value;
    return thisSerializableObject->is_equivalent_to(
            *otherSerializableObject);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    clone
 * Signature:
 * (Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentimelineio/SerializableObject;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_clone(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto clonedHandle = thisSerializableObject->clone(errorStatusHandle);
    return serializableObjectFromNative(env, clonedHandle);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    dynamicFields
 * Signature: ()Lio/opentimeline/opentimelineio/AnyDictionary;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_dynamicFields(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    auto result = thisSerializableObject->dynamic_fields();
    return anyDictionaryFromNative(env, &result);
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    isUnknownSchema
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_isUnknownSchema(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    return thisSerializableObject->is_unknown_schema();
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    schemaName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_schemaName(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    return env->NewStringUTF(thisSerializableObject->schema_name().c_str());
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    schemaVersion
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_schemaVersion(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    return thisSerializableObject->schema_version();
}

/*
 * Class:     io_opentimeline_opentimelineio_SerializableObject
 * Method:    currentRefCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_io_opentimeline_opentimelineio_SerializableObject_currentRefCount(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<SerializableObject>>(env, thisObj);
    auto thisSerializableObject = thisHandle->value;
    return thisSerializableObject->current_ref_count();
}
