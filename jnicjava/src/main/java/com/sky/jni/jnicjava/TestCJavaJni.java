package com.sky.jni.jnicjava;

import android.util.Log;

/**
 * Created by BlueSky on 16/11/24.
 *
 * c调用java代码
 */

public class TestCJavaJni {

    static
    {
        System.loadLibrary("testcJava");
    }
    /**
     * 当该方法执行的时候让c代码调用add(int x,int y)
     */
    public native int callBackAdd();
    /**
     *当该方法执行的时候让c代码调用helloFromJava()
     */
    public native void callBackFromJava();
    /**
     *当该方法执行的时候让c代码调用printString(String s)
     */
    public native void callPrintString();
    /**
     *当该方法执行的时候让c代码调用sayHello(String s)
     */
    public   native void   callBackSayHello();


    public native  String  callBackResultStr(String str);

    public  int  add(int x,int y){
        Log.e("====","x+y="+(x+y));
        return x+y;
    }

    public void   helloFromJava(){
        Log.e("====","Hello,我是java过来的内容");
    }

    public  void printString(String s){
        Log.e("====","c中输入的是："+s);
    }

    public  static  void  sayHello(String s){
       // String s1="Hello,我是java中jni，c代码调用了java的静态的sayHello(String s)方法：";
        Log.e("====",s);
     // return s1+s;

    }


    public  static  String  getResultStr(String s){
         String s1="Hello,我是java中jni，c代码调用了java的静态的sayHello(String s)方法：";
        Log.e("====",s);
         return s1+s;

    }
}
