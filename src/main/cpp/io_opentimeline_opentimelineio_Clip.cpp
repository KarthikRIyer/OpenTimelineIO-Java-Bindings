// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

#include <exceptions.h>
#include <handle.h>
#include <io_opentimeline_opentimelineio_Clip.h>
#include <opentimelineio/clip.h>
#include <opentimelineio/version.h>
#include <utilities.h>

using namespace opentimelineio::OPENTIMELINEIO_VERSION;

/*
 * Class:     io_opentimeline_opentimelineio_Clip
 * Method:    initialize
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/MediaReference;Lio/opentimeline/opentime/TimeRange;Lio/opentimeline/opentimelineio/AnyDictionary;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_Clip_initialize(
        JNIEnv *env,
        jobject thisObj,
        jstring name,
        jobject mediaReferenceObj,
        jobject sourceRangeObj,
        jobject metadataObj) {
    if (metadataObj == nullptr)
        throwNullPointerException(env, "");
    else {
        std::string nameStr = env->GetStringUTFChars(name, 0);
        OTIO_NS::optional<TimeRange> sourceRange = OTIO_NS::nullopt;
        if (sourceRangeObj != nullptr) { sourceRange = timeRangeFromJObject(env, sourceRangeObj); }
        auto metadataHandle =
                getHandle<AnyDictionary>(env, metadataObj);
        MediaReference *mediaReference = nullptr;
        if (mediaReferenceObj != nullptr) {
            auto mediaReferenceHandle =
                    getHandle<SerializableObject::Retainer<MediaReference>>(env, mediaReferenceObj);
            mediaReference = mediaReferenceHandle->value;
        }
        auto clip = new OTIO_NS::Clip(
                nameStr, mediaReference, sourceRange, *metadataHandle);
        auto clipManager = new SerializableObject::Retainer<Clip>(clip);
        setHandle(env, thisObj, clipManager);
    }
}

/*
 * Class:     io_opentimeline_opentimelineio_Clip
 * Method:    setMediaReference
 * Signature: (Lio/opentimeline/opentimelineio/MediaReference;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_Clip_setMediaReference(
        JNIEnv *env, jobject thisObj, jobject mediaReferenceObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Clip>>(env, thisObj);
    auto clip = thisHandle->value;
    MediaReference *mediaReference = nullptr;
    if (mediaReferenceObj != nullptr) {
        auto mediaReferenceHandle =
                getHandle<SerializableObject::Retainer<MediaReference>>(env, mediaReferenceObj);
        mediaReference = mediaReferenceHandle->value;

    }
    clip->set_media_reference(mediaReference);
}

/*
 * Class:     io_opentimeline_opentimelineio_Clip
 * Method:    getMediaReference
 * Signature: ()Lio/opentimeline/opentimelineio/MediaReference;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Clip_getMediaReference(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Clip>>(env, thisObj);
    auto clip = thisHandle->value;
    auto result = clip->media_reference();
    return mediaReferenceFromNative(env, result);
}

/*
 * Class:     io_opentimeline_opentimelineio_Clip
 * Method:    getAvailableRange
 * Signature: (Lio/opentimeline/opentimelineio/ErrorStatus;)Lio/opentimeline/opentime/TimeRange;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_Clip_getAvailableRange(
        JNIEnv *env, jobject thisObj, jobject errorStatusObj) {
    if (errorStatusObj == nullptr) {
        throwNullPointerException(env, "");
        return nullptr;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<Clip>>(env, thisObj);
    auto clip = thisHandle->value;
    auto errorStatusHandle =
            getHandle<OTIO_NS::ErrorStatus>(env, errorStatusObj);
    auto result = clip->available_range(errorStatusHandle);
    return timeRangeToJObject(env, result);
}
