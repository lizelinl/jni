package com.example.testjni;

import android.util.Log;

public class DataProvider {
	public native String StringFromJNI();
	
	public native String sayHello(String s);
	
	public native int add(int x,int y);
	
	public native int[] intMethod(int[] arr);
	
	//c�ص�java�ķ���
	public native void cvoidhello();
	public void csayhello() {
		Log.i("lzl", "csayhello");
	}
	//c�ص�����int����java�ķ���
	public native void cintMethod();
	public int cCallAdd(int x,int y){
		Log.i("lzl", "cCallAdd");
		return x+y;
	}
	//c�ص�string����java�ķ���
	public native void cstringMethod();
	public void cCallString(String s){
		Log.i("lzl", s+"");
	}
	
	
}
