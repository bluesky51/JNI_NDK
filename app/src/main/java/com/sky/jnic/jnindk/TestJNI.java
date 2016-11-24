package com.sky.jnic.jnindk;

/**
 * Created by BlueSky on 16/11/15.
 * 作用：java调用对应的c代码
 */
public class TestJNI {
    //加载so库
    static {
        System.loadLibrary("Hello");
    }

    /**
     * 定义native方法
     * 调用c代码对应的方法
     *
     * @return
     */
    public native String sayHello();

    //java传递参数给c代码，让c代码执行运算返回结果
    public native int sum(int x, int y);

    //java传递参数str给c代码，供c代码使用
    public native String strCat(String str);

    //让c代码给每个元素的值加上10
    public native int[] increaseArray(int[] array);

    //检查密码是否正确，正确返回true,错误返回false
    public native boolean checkPwd(String str);
}
