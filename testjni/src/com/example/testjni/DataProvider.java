package com.example.testjni;

import android.util.Log;

public class DataProvider {
	public native String StringFromJNI();
	
	public native String sayHello(String s);
	
	public native int add(int x,int y);
	
	public native int[] intMethod(int[] arr);
	
	//c回调java的方法
	public native void cvoidhello();
	public void csayhello() {
		Log.i("lzl", "csayhello");
	}
	//c回调两个int类型java的方法
	public native void cintMethod();
	public int cCallAdd(int x,int y){
		Log.i("lzl", "cCallAdd");
		return x+y;
	}
	//c回调string类型java的方法
	public native void cstringMethod();
	public void cCallString(String s){
		Log.i("lzl", s+"");
	}
	
	
}
