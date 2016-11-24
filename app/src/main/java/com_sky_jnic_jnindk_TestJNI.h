/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net_sourceforge_simcpux_jnindk_TestJNI */

#ifndef _Included_com_sky_jnic_jnindk_TestJNI
#define _Included_com_sky_jnic_jnindk_TestJNI

JNIEXPORT void JNICALL
Java_com_sky_jnic_jnindk_TestCJavaJni_callBackShowToast(JNIEnv *env,
                                                                     jobject instance) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_sky_jnic_jnindk_MainActivity_callBackShowToast(JNIEnv *env,
                                                                     jobject instance) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_sky_jnic_jnindk_TestCJavaJni_callBackSayHello(JNIEnv *env, jobject instance) {

    // TODO


    return env->NewStringUTF(returnValue);
}



JNIEXPORT jstring JNICALL
Java_com_sky_jnic_jnindk_TestCJavaJni_callBackResultStr(JNIEnv *env, jobject instance,
                                                                     jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    // TODO

    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF(returnValue);
}

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     net_sourceforge_simcpux_jnindk_TestJNI
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sky_jnic_jnindk_TestJNI_sayHello
  (JNIEnv *, jobject);

/*
 * Class:     net_sourceforge_simcpux_jnindk_TestJNI
 * Method:    sum
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_sky_jnic_jnindk_TestJNI_sum
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     net_sourceforge_simcpux_jnindk_TestJNI
 * Method:    strCat
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sky_jnic_jnindk_TestJNI_strCat
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_sourceforge_simcpux_jnindk_TestJNI
 * Method:    increaseArray
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_sky_jnic_jnindk_TestJNI_increaseArray
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     net_sourceforge_simcpux_jnindk_TestJNI
 * Method:    checkPwd
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_sky_jnic_jnindk_TestJNI_checkPwd
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif