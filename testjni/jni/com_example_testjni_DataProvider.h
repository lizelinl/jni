/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_testjni_DataProvider */

#ifndef _Included_com_example_testjni_DataProvider
#define _Included_com_example_testjni_DataProvider
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_example_testjni_MainActivity
 * Method:    StringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_testjni_DataProvider_StringFromJNI
  (JNIEnv *, jobject);
/*
 * Class:     com_example_testjni_DataProvider
 * Method:    sayHello
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_testjni_DataProvider_sayHello
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_example_testjni_DataProvider
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_testjni_DataProvider_add
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_example_testjni_DataProvider
 * Method:    intMethod
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_example_testjni_DataProvider_intMethod
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_example_testjni_DataProvider
 * Method:    cvoidhello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cvoidhello
  (JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cintMethod
  (JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cstringMethod
  (JNIEnv *, jobject);
#ifdef __cplusplus
}
#endif
#endif