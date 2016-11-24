package com.sky.jni.jnicjava;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
    TestCJavaJni testCJavaJni;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) findViewById(R.id.textView);
        testCJavaJni =new TestCJavaJni();
    }

    public void add(View view){
       int sum =  testCJavaJni.callBackAdd();
        textView.setText("c计算得到的结果是:"+sum);
    }

    public void helloFromJava(View view){
        testCJavaJni.callBackFromJava();
    }

    public void printString(View view){
        testCJavaJni.callPrintString();
    }

    public void sayHello(View view){
         testCJavaJni.callBackSayHello();
    }
    public void strcat(View view){
        String str = testCJavaJni.callBackResultStr("嗯嗯呢嗯");
        textView.setText(str);
    }
    public void showToast(View view){
        callBackShowToast();
    }

    public void showToast(String string){
        Toast.makeText(this,string+"哈哈哈哈！",Toast.LENGTH_LONG).show();
    }
    /**
     *当该方法执行的时候让c代码调用MainActivity中的sayHello(String s)
     */
    public native void callBackShowToast();

}
