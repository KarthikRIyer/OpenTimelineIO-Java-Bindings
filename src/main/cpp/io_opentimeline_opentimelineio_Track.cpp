// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

#include <exceptions.h>
#include <handle.h>
#include <io_opentimeline_opentimelineio_Track.h>
#include <opentimelineio/errorStatus.h>
#include <opentimelineio/track.h>
#include <opentimelineio/version.h>
#include <utilities.h>

using namespace opentimelineio::OPENTIMELINEIO_VERSION;

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    initialize
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentime/TimeRange;Ljava/lang/String;Lio/opentimeline/opentimelineio/AnyDictionary;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_Track_initialize(
        JNIEnv *env,
        jobject thisObj,
        jstring name,
        jobject sourceRangeObj,
        jstring kind,
        jobject metadataObj) {
    if (name == nullptr || metadataObj == nullptr) {
        throwNullPointerException(env, "");
        return;
    }
    std::string nameStr = env->GetStringUTFChars(name, 0);
    std::string kindStr = env->GetStringUTFChars(kind, 0);
    optional<TimeRange> sourceRange = nullopt;
    if (sourceRangeObj != nullptr) { sourceRange = timeRangeFromJObject(env, sourceRangeObj); }
    auto metadataHandle =
            getHandle<AnyDictionary>(env, metadataObj);
    auto track =
            new Track(nameStr, sourceRange, kindStr, *metadataHandle);
    auto trackManager =
            new SerializableObject::Retainer<Track>(track);
    setHandle(env, thisObj, trackManager);
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    getKind
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_opentimeline_opentimelineio_Track_getKind(JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    return env->NewStringUTF(track->kind().c_str());
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    setKind
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_Track_setKind(
        JNIEnv *env, jobject thisObj, jstring kind) {
    if (kind == nullptr) {
        throwNullPointerException(env, "");
        return;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    std::string kindStr = env->GetStringUTFChars(kind, nullptr);
    track->set_kind(kindStr);
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    rangeOfChildAtIndex
 * Signature: (ILio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentime/TimeRange;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_rangeOfChildAtIndex(
        JNIEnv *env, jobject thisObj, jint index, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = track->range_of_child_at_index(index, errorStatusHandle);
    return timeRangeToJObject(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    trimmedRangeOfChildAtIndex
 * Signature: (ILio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentime/TimeRange;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_trimmedRangeOfChildAtIndex(
        JNIEnv *env, jobject thisObj, jint index, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result =
            track->trimmed_range_of_child_at_index(index, errorStatusHandle);
    return timeRangeToJObject(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    getAvailableRange
 * Signature: (Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentime/TimeRange;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_getAvailableRange(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = track->available_range(errorStatusHandle);
    return timeRangeToJObject(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    getHandlesOfChild
 * Signature: (Lio/opentimeline/opentimelineio/Composable;Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/util/Pair;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_getHandlesOfChild(
        JNIEnv *env,
        jobject thisObj,
        jobject composableChild,
        jobject errorStatusObj) {
    if (errorStatusObj == nullptr || composableChild == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto childHandle =
            getHandle<SerializableObject::Retainer<Composable>>(env, composableChild);
    auto child = childHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = track->handles_of_child(child, errorStatusHandle);

    jobject first = (result.first != OTIO_NS::nullopt)
                    ? rationalTimeToJObject(env, result.first.value())
                    : nullptr;
    jobject second = (result.second != OTIO_NS::nullopt)
                     ? rationalTimeToJObject(env, result.second.value())
                     : nullptr;

    jclass pairClass = env->FindClass("io/opentimeline/util/Pair");
    jmethodID pairInit = env->GetMethodID(
            pairClass, "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    jobject pairObject = env->NewObject(pairClass, pairInit, first, second);
    return pairObject;
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    getNeighborsOfNative
 * Signature: (Lio/opentimeline/opentimelineio/Composable;Lio/opentimeline/opentimelineio/ErrorStatus;I)Lio/opentimeline/util/Pair;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_getNeighborsOfNative(
        JNIEnv *env,
        jobject thisObj,
        jobject itemComposableObj,
        jobject errorStatusObj,
        jint neighbourGapPolicyIndex) {
    if (errorStatusObj == nullptr || itemComposableObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto itemHandle =
            getHandle<SerializableObject::Retainer<Composable>>(env, itemComposableObj);
    auto item = itemHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    std::pair<
            SerializableObject::Retainer<Composable>,
            SerializableObject::Retainer<Composable>>
            result = track->neighbors_of(
            item,
            errorStatusHandle,
            Track::NeighborGapPolicy(neighbourGapPolicyIndex));

    jobject first = composableFromNative(env, result.first);
    jobject second = composableFromNative(env, result.second);

    jclass pairClass = env->FindClass("io/opentimeline/util/Pair");
    jmethodID pairInit = env->GetMethodID(
            pairClass, "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    jobject pairObject = env->NewObject(pairClass, pairInit, first, second);
    return pairObject;
}

/*
 * Class:     io_opentimeline_opentimelineio_Track
 * Method:    getRangeOfAllChildren
 * Signature: (Lio/opentimeline/opentimelineio/ErrorStatus;)Ljava/util/HashMap;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Track_getRangeOfAllChildren(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Track>>(env, thisObj);
    auto track = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = track->range_of_all_children(errorStatusHandle);

    jclass hashMapClass = env->FindClass("java/util/HashMap");
    jmethodID hashMapInit = env->GetMethodID(hashMapClass, "<init>", "(I)V");
    jobject hashMapObj =
            env->NewObject(hashMapClass, hashMapInit, result.size());
    jmethodID hashMapPut = env->GetMethodID(
            hashMapClass,
            "put",
            "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    for (auto it: result) {
        auto first = it.first;
        auto second = it.second;
        jobject composableObject = composableFromNative(env, first);
        jobject tr = timeRangeToJObject(env, second);

        env->CallObjectMethod(hashMapObj, hashMapPut, composableObject, tr);
    }

    return hashMapObj;
}