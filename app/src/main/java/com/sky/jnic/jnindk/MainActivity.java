package com.sky.jnic.jnindk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView textView;
    TestJNI testJNI;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) findViewById(R.id.tv);
        testJNI = new com.sky.jnic.jnindk.TestJNI();
    }

    public void sayHello(View view) {
        String str = testJNI.sayHello();
        textView.setText(str);

    }

    public void sum(View view) {
        int result = testJNI.sum(3, 5);
        textView.setText("使用c代码计算得到的结果是：" + result);

    }

    public void strCat(View view) {
        String result = testJNI.strCat("哈喽,C,好久不见！");
        textView.setText(result);

    }


    public void increaseArray(View view) {
        int[] array={1,2,3,4,5};
        int[] intArray = testJNI.increaseArray(array);
        String result="";
        for (int i = 0; i <intArray.length ; i++) {
            int j = intArray[i];
            result+="第"+(i+1)+"个元素的值为:"+j+"\n";
        }
        textView.setText(result);
    }

    public void checkPwd(View view){
       boolean b =  testJNI.checkPwd("123456");
        if (b==true){
            textView.setText("密码正确，可登陆");
        }else{
            textView.setText("密码错误，无法登陆");
        }
    }
}
