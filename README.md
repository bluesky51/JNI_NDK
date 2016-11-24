1.AndroidStudio(AS)安装配置ndk;
    1>下载各个系统版本的NDK网址：http://www.androiddevtools.cn/
    2>解压ndk的压缩包在非中文的目录下；
    3>配置路径:
    方式一：菜单栏File-project Structure-SDK Location-Android NDK Location-输入解压缩的ndk路径
    方式二：1》在Project目录下的local.properties中添加如下话语：
           sdk.dir=ndk解压缩的ndk路径
           2》在在Project目录下的gradle.properties中添加如下话语：
           ＃兼容老的版本
           android.useDeprecatedNdk=true
2.ndk开发流程；
    1>在java里面写native代码,示例如下：
        package net.sourceforge.simcpux.jnindk;
        /**
         * Created by BlueSky on 16/11/15.
         * 作用：java调用对应的c代码
         */
        public class TestJNI {
            //加载so库
            static
            {
                System.loadLibrary("Hello");
            }
            /**
             * 定义native方法
             * 调用c代码对应的方法
             * @return
             */
            public  native String sayHello();
         }
    2>在main目录下创建jni目录，在该目录下写c代码:
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
        jstring Java_net_sourceforge_simcpux_jnindk_TestJNI_sayHello(JNIEnv *env,
                                                                      jobject obj){
        /**
        * jstring     (*NewStringUTF)(JNIEnv*, const char*);
        */
         char *text="Hello,我是底层发过来的c库";
         return (*env)->NewStringUTF(env,text);
        }
    3>配置动态链接库的名称；
    备注:在Module下build.gradle 的android的子标签defaultConfig中添加如下话语：
     ndk{
                moduleName "Hello"//so文件:lib＋moduleName+.so
                abiFilters"armeabi","armeabi-v7a","x86" //cpu类型
        }
    4>加载动态链接库；提示:使用静态代码块以及System.loadLibrary加载
    5>使用:
    备注：对带有native声明的方法的java类要生成对应的.h文件做如下操作即可
    1》用AndroidStudio自带的Terminal(终端)进行处理,
       《1》先切换目录到当前带有native声明的方法的java类的目录cd xxxx；
       《2》执行命令 javah 包名+带有native声明的方法的java类的类名
       《3》再在jni目录的c类中实现该方法
