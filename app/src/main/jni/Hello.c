//
// Created by bluesky on 16/11/23.
//

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>


/**
*jstring:返回值
＊Java_全类名_方法名
*JNIEnv* env:里面有很多方法
＊jobject obj:谁调用了这个方法就是谁的实例
              当前就是TestJNI.this
*/
jstring Java_com_sky_jnic_jnindk_TestJNI_sayHello(JNIEnv *env,
                                                             jobject obj) {


    // jstring     (*NewStringUTF)(JNIEnv*, const char*);
    char *text = "Hello,我是底层发过来的c库";
    return (*env)->NewStringUTF(env, text);
}

jint Java_com_sky_jnic_jnindk_TestJNI_sum
        (JNIEnv *env, jobject jobj, jint jint1, jint jint2) {
    return jint1 + jint2;
}

/**
 *  字符串拼接(c代码调用java传递过来的参数)：
 *  jstring:返回值
 *  Java_全类名_方法名
 *  JNIEnv* env:里面有很多方法
 *  jobject obj:谁调用了这个方法就是谁的实例。当前就是TestJNI.this
 *  jstring jstring1：从java代码传入的字符串
 */
jstring Java_com_sky_jnic_jnindk_TestJNI_strCat
        (JNIEnv *env, jobject jobj, jstring jstring1) {
    //将jstring转换成char*字符
    char *fromJava = (*env)->GetStringUTFChars(env, jstring1, JNI_FALSE);
    char *fromC = "\n哈喽,Java,好久不见！";
    //字符串连接
    char *result = strcat(fromJava, fromC);
    return (*env)->NewStringUTF(env, result);
}

/**
 * 给数组中的每个值加10
 * jstring:返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * object obj:谁调用了这个方法就是谁的实例。当前就是TestJNI.this
 * jintArray jintArray1：从java代码传入的字符串
 */
jintArray Java_com_sky_jnic_jnindk_TestJNI_increaseArray
        (JNIEnv *env, jobject jobject1, jintArray jintArray1) {
    //获取数组长度
    jsize jsize1 = (*env)->GetArrayLength(env, jintArray1);

    //得到数组元素(false原空间进行操作,true另开辟空间操作)
    jint *jint1 = (*env)->GetIntArrayElements(env, jintArray1, JNI_FALSE);
    //遍历数组，给每个元素加10
    for (int i = 0; i < jsize1; ++i) {
        *(jint1 + i) += 10;
    }
    //返回结果
    return jintArray1;
}

/**
 *检查密码是否正确
 * jboolean:返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * object obj:谁调用了这个方法就是谁的实例。当前就是TestJNI.this
 * jstring jstring1：从java代码传入的字符串密码
 */
jboolean Java_com_sky_jnic_jnindk_TestJNI_checkPwd
        (JNIEnv *env, jobject jobject1, jstring jstring1) {
    //把jstring转化成char*
    char *fromServer = (*env)->GetStringUTFChars(env, jstring1, JNI_FALSE);
    char *fromUser = "123456";
    //两个char*进行比较
    int code = strcmp(fromServer, fromUser);
    if (code == 0) {
        return JNI_TRUE;
    } else {

        return JNI_FALSE;
    }


}

