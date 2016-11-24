//
// Created by bluesky on 16/11/24.
//

#include <jni.h>
#include <stdio.h>
#include <android/log.h>
#include <stdlib.h>

#define  LOG_TAG    "===="
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

/**
 * 让c代码调用java中TestCJava类的add(int x,int y)方法
 */
jint  Java_com_sky_jni_jnicjava_TestCJavaJni_callBackAdd
        (JNIEnv *env, jobject jobject1){
    //1.利用反射找到该类的字节码文件
    // 方法原型：jclass   (*FindClass)(JNIEnv*, const char*);
    //参数2表示的是c代码要调用的类的全称：包名+类名(其中.都改成／表示目录)
    jclass  jclass1 = (*env)->FindClass(env,"com/sky/jni/jnicjava/TestCJavaJni");
    //2.找到该类当中的方法
    //方法原型：jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    /**
     * 参数1:方法所在的类的对象
     * 参数2:方法名
     * 参数3:1>方法签名(控制台切换目录到项目的module目录下的build/intermediates/classes/debug),
     *      示例： cd /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/jnicjava/build/intermediates/classes/debug
     *      2>在以上目录下，执行如下命令：
     *      javap -s 包名+类名(方法所在的类)
     */
    jmethodID jmethodID1 = (*env)->GetMethodID(env,jclass1,"add","(II)I");
    //3.实例化该类
    jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    //4。c代码调用java方法，结果在java代码中输出
    //方法原型：jint  (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint  jint1 = (*env)->CallIntMethod(env,jobject2,jmethodID1,88,12);
    LOGE("运算得到的结果是＝＝＝＝%d\n",jint1);
    return jint1;
}

void  Java_com_sky_jni_jnicjava_TestCJavaJni_callBackFromJava
        (JNIEnv *env, jobject jobject1){
    //1.利用反射找到该类的字节码文件
    // 方法原型：jclass   (*FindClass)(JNIEnv*, const char*);
    //参数2表示的是c代码要调用的类的全称：包名+类名(其中.都改成／表示目录)
    jclass  jclass1  = (*env)->FindClass(env,"com/sky/jni/jnicjava/TestCJavaJni");
    //2.找到该类当中的方法
    //方法原型：jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    /**
     * 参数1:方法所在的类的对象
     * 参数2:方法名
     * 参数3:1>方法签名(控制台切换目录到项目的module目录下的build/intermediates/classes/debug),
     *      示例： cd /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/jnicjava/build/intermediates/classes/debug
     *      2>在以上目录下，执行如下命令：
     *      javap -s 包名+类名(方法所在的类)
     */
    jmethodID jmethodID1 = (*env)->GetMethodID(env,jclass1,"helloFromJava","()V");
    //3.实例化该类
    jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    //4。c代码调用java方法，结果在java代码中输出
    //方法原型：  void  (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,jobject2,jmethodID1);
    LOGE("c代码调用java中helloFromJava()方法");

}

void  Java_com_sky_jni_jnicjava_TestCJavaJni_callPrintString
        (JNIEnv *env, jobject jobject1){
//1.利用反射找到该类的字节码文件
    // 方法原型：jclass   (*FindClass)(JNIEnv*, const char*);
    //参数2表示的是c代码要调用的类的全称：包名+类名(其中.都改成／表示目录)
    jclass  jclass1  = (*env)->FindClass(env,"com/sky/jni/jnicjava/TestCJavaJni");
    //2.找到该类当中的方法
    //方法原型：jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    /**
     * 参数1:方法所在的类的对象
     * 参数2:方法名
     * 参数3:1>方法签名(控制台切换目录到项目的module目录下的build/intermediates/classes/debug),
     *      示例： cd /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/jnicjava/build/intermediates/classes/debug
     *      2>在以上目录下，执行如下命令：
     *      javap -s 包名+类名(方法所在的类)
     */
    jmethodID jmethodID1 = (*env)->GetMethodID(env,jclass1,"printString","(Ljava/lang/String;)V");
    //3.实例化该类
    jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    //把char＊转换成jstring
    jstring jstring1 =(*env)->NewStringUTF(env,"么么哒");
    //4。c代码调用java方法，结果在java代码中输出
    //方法原型：  void  (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,jobject2,jmethodID1,jstring1);
    LOGE("c代码调用java中printString()方法");
}
void  Java_com_sky_jni_jnicjava_TestCJavaJni_callBackSayHello(JNIEnv *env, jobject instance) {
    //1.利用反射找到该类的字节码文件
    // 方法原型：jclass   (*FindClass)(JNIEnv*, const char*);
    //参数2表示的是c代码要调用的类的全称：包名+类名(其中.都改成／表示目录)
    jclass  jclass1  = (*env)->FindClass(env,"com/sky/jni/jnicjava/TestCJavaJni");
    //2.找到该类当中的方法
    //方法原型：jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    /**
     * 参数1:方法所在的类的对象
     * 参数2:方法名
     * 参数3:1>方法签名(控制台切换目录到项目的module目录下的build/intermediates/classes/debug),
     *      示例： cd /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/jnicjava/build/intermediates/classes/debug
     *      2>在以上目录下，执行如下命令：
     *      javap -s 包名+类名(方法所在的类)
     */
    jmethodID jmethodID1 = (*env)->GetStaticMethodID(env,jclass1,"sayHello","(Ljava/lang/String;)V");
    //3.实例化该类
    jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    //把char＊转换成jstring
    jstring jstring1 =(*env)->NewStringUTF(env,"哈哈哈哈");
    //4。c代码调用java方法，结果在java代码中输出
    //方法原型：  void  (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,jobject2,jmethodID1,jstring1);
    LOGE("c代码调用java中sayHello()方法");


}

void Java_com_sky_jni_jnicjava_MainActivity_callBackShowToast(JNIEnv *env,
                                                                     jobject instance) {
    //1.利用反射找到该类的字节码文件
    // 方法原型：jclass   (*FindClass)(JNIEnv*, const char*);
    //参数2表示的是c代码要调用的类的全称：包名+类名(其中.都改成／表示目录)
    jclass  jclass1  = (*env)->FindClass(env,"com/sky/jni/jnicjava/MainActivity");
    //2.找到该类当中的方法
    //方法原型：jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    /**
     * 参数1:方法所在的类的对象
     * 参数2:方法名
     * 参数3:1>方法签名(控制台切换目录到项目的module目录下的build/intermediates/classes/debug),
     *      示例： cd /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/jnicjava/build/intermediates/classes/debug
     *      2>在以上目录下，执行如下命令：
     *      javap -s 包名+类名(方法所在的类)
     */
    jmethodID jmethodID1 = (*env)->GetMethodID(env,jclass1,"showToast","(Ljava/lang/String;)V");
    //3.实例化该类
    //jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    //把char＊转换成jstring
    jstring jstring1 =(*env)->NewStringUTF(env,"我是c代码发过来的");
    //4。c代码调用java方法，结果在java代码中输出
    //方法原型：  void  (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,instance,jmethodID1,jstring1);
    LOGE("c代码调用java中showToast()方法");
}

jstring Java_com_sky_jni_jnicjava_TestCJavaJni_callBackResultStr(JNIEnv *env, jobject instance,
                                                                     jstring str_){

    jclass  jclass1  = (*env)->FindClass(env,"com/sky/jni/jnicjava/TestCJavaJni");
    jmethodID jmethodID1 = (*env)->GetStaticMethodID(env,jclass1,"getResultStr","(Ljava/lang/String;)Ljava/lang/String;");
    //3.实例化该类
    jobject  jobject2 =(*env)->AllocObject(env,jclass1);
    jstring  jstring2 =  (*env)->CallObjectMethod(env,jobject2,jmethodID1,str_);

   return jstring2;
}