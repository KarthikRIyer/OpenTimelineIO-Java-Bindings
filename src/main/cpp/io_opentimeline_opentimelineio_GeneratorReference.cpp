// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

#include <exceptions.h>
#include <handle.h>
#include <io_opentimeline_opentimelineio_GeneratorReference.h>
#include <opentimelineio/generatorReference.h>
#include <opentimelineio/optional.h>
#include <opentimelineio/version.h>
#include <utilities.h>

using namespace opentimelineio::OPENTIMELINEIO_VERSION;

/*
 * Class:     io_opentimeline_opentimelineio_GeneratorReference
 * Method:    initialize
 * Signature: (Ljava/lang/String;Ljava/lang/String;Lio/opentimeline/opentime/TimeRange;Lio/opentimeline/opentimelineio/AnyDictionary;Lio/opentimeline/opentimelineio/AnyDictionary;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_GeneratorReference_initialize(
        JNIEnv *env,
        jobject thisObj,
        jstring name,
        jstring generatorKind,
        jobject availableRangeObj,
        jobject parameters,
        jobject metadata) {
    if (name == nullptr || generatorKind == nullptr || parameters == nullptr ||
        metadata == nullptr)
        throwNullPointerException(env, "");
    else {
        std::string nameStr = env->GetStringUTFChars(name, 0);
        std::string generatorKindStr = env->GetStringUTFChars(generatorKind, 0);
        optional<TimeRange> availableRange = nullopt;
        if (availableRangeObj != nullptr) { availableRange = timeRangeFromJObject(env, availableRangeObj); }
        auto parametersHandle =
                getHandle<AnyDictionary>(env, parameters);
        auto metadataHandle = getHandle<AnyDictionary>(env, metadata);
        auto generatorReference = new GeneratorReference(
                nameStr,
                generatorKindStr,
                availableRange,
                *parametersHandle,
                *metadataHandle);
        auto mrManager =
                new SerializableObject::Retainer<GeneratorReference>(generatorReference);
        setHandle(env, thisObj, mrManager);
    }
}

/*
 * Class:     io_opentimeline_opentimelineio_GeneratorReference
 * Method:    getGeneratorKind
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_opentimeline_opentimelineio_GeneratorReference_getGeneratorKind(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<GeneratorReference>>(env, thisObj);
    auto mr = thisHandle->value;
    return env->NewStringUTF(mr->generator_kind().c_str());
}

/*
 * Class:     io_opentimeline_opentimelineio_GeneratorReference
 * Method:    setGeneratorKind
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_GeneratorReference_setGeneratorKind(
        JNIEnv *env, jobject thisObj, jstring generatorKind) {
    if (generatorKind == nullptr) {
        throwNullPointerException(env, "");
        return;
    }
    auto thisHandle =
            getHandle<SerializableObject::Retainer<GeneratorReference>>(env, thisObj);
    auto mr = thisHandle->value;
    std::string generatorKindStr = env->GetStringUTFChars(generatorKind, 0);
    mr->set_generator_kind(generatorKindStr);
}

/*
 * Class:     io_opentimeline_opentimelineio_GeneratorReference
 * Method:    getParameters
 * Signature: ()Lio/opentimeline/opentimelineio/AnyDictionary;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_GeneratorReference_getParameters(
        JNIEnv *env, jobject thisObj) {
    auto thisHandle =
            getHandle<SerializableObject::Retainer<GeneratorReference>>(env, thisObj);
    auto mr = thisHandle->value;
    return anyDictionaryFromNative(env, &(mr->parameters()));
}
