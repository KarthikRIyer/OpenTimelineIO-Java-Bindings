/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class io_opentimeline_opentimelineio_AnyDictionary */

#ifndef _Included_io_opentimeline_opentimelineio_AnyDictionary
#define _Included_io_opentimeline_opentimelineio_AnyDictionary
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_initialize
  (JNIEnv *, jobject);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    containsKey
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_containsKey
  (JNIEnv *, jobject, jstring);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    get
 * Signature: (Ljava/lang/String;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_get
  (JNIEnv *, jobject, jstring);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    put
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_put
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    replace
 * Signature: (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_replace
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_size
  (JNIEnv *, jobject);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_clear
  (JNIEnv *, jobject);

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    remove
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_remove
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
