package com.example.testjni;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

public class MainActivity extends Activity {
	static{
		System.loadLibrary("testjni");
	}
	private DataProvider dp;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		dp=new DataProvider();
		/*
		 * sayhello
		 */
		//Toast.makeText(this, StringFromJNI(), 1).show();
		/*
		 * java����int���Ͳ�����c
		 */
		//Toast.makeText(this, dp.add(1, 2)+"", 1).show();
		/*
		 * java����string���Ͳ�����c
		 */
 		//Toast.makeText(this, dp.sayHello("LIZELIN")+"", 1).show();
 		 /*
 		  *java���������c 
 		  */
//		int[] i ={1,2,3,4,5};
//		int[] result = dp.intMethod(i);
//		for(int j=0;j<result.length;j++){
//			
//			Log.i("lzl",result[j]+"");
//		}
		/**
		 * ����native���� �ص�java����
		 */
		//dp.cvoidhello();
		/**
		 * ����native���� �ص�int����
		 */
		 //dp.cintMethod();
		/**
		 * 
		 */
		dp.cstringMethod();
		
	}	
}
