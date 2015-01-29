#include <jni.h>
#include <stdlib.h>
#include <malloc.h>

#include "com_example_testjni_DataProvider.h"
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

/**
 * JAVA字符串转c识别的字符串
 */
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //"\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
	 return rtn;
}

JNIEXPORT jstring JNICALL Java_com_example_testjni_DataProvider_StringFromJNI
  (JNIEnv * env , jobject obj){

	char* s="12";
	LOGD("jni日志");

	return (*env)->NewStringUTF(env,"hello world");
}

JNIEXPORT jstring JNICALL Java_com_example_testjni_DataProvider_sayHello
  (JNIEnv * env, jobject obj, jstring str){

	//将java的字符串转为c的字符串
	char* s=Jstring2CStr(env,str);
	//联合字符串
	strcat(s,"12");
	//将c字符串转换为java所识别的字符串
	jstring str1 =(*env)->NewStringUTF(env,s);

	return str1;
}

JNIEXPORT jint JNICALL Java_com_example_testjni_DataProvider_add
  (JNIEnv * env, jobject obj, jint x, jint y){

	return x+y;
}
JNIEXPORT jintArray JNICALL Java_com_example_testjni_DataProvider_intMethod
  (JNIEnv * env, jobject obj, jintArray jarr){

    jsize len= (*env)->GetArrayLength(env,jarr);

	jint* arr = (*env)->GetIntArrayElements(env,jarr,0);
	int i;
	for(i=0;i<len;i++){

		*(arr+i)+=10;
	}
	return jarr;


}
//C回调java方法

JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cvoidhello
  (JNIEnv * env, jobject objs){
	/**
	 * 把要在c中将要调用的java方法的包名和类型定义
	 */
	LOGD("111");
	char* classname = "com/example/testjni/DataProvider";
	LOGD("222");
	jclass clazz=(*env)->FindClass(env,classname);
	/*
	 * 参数说明，从第三个开始
		第三个参数：要调用的java方法中的方法名
		第四个参数：该方法的签名，通过javap –s 包名+类名获得
	 *
	 */
	LOGD("333");
	jmethodID method =(*env)->GetMethodID(env,clazz,"csayhello","()V");

	/*
	 * 调用这个方法
		(*env)->CallVoidMethod(env,obj,method);
			如果是返回值是void就调用CallVoidMethod，是int就调用
			int result = CallIntMethod(env,obj,method);
	 *
	 */

	(*env)->CallVoidMethod(env,objs,method);

}



JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cintMethod
  (JNIEnv * env, jobject objs){

	char* classname="com/example/testjni/DataProvider";
	jclass clazz=(*env)->FindClass(env,classname);
	jmethodID method =(*env)->GetMethodID(env,clazz,"cCallAdd","(II)I");
	jint res=(*env)->CallIntMethod(env,objs,method,99,11);
	LOGD("result:%d",res);
}

JNIEXPORT void JNICALL Java_com_example_testjni_DataProvider_cstringMethod
  (JNIEnv * env, jobject objs){

	char* classname="com/example/testjni/DataProvider";
	jclass clazz=(*env)->FindClass(env,classname);
	jmethodID method =(*env)->GetMethodID(env,clazz,"cCallString","(Ljava/lang/String;)V");
	char* str = "adsd";
	jstring jstr = (*env)->NewStringUTF(env,str);
	 (*env)->CallVoidMethod(env,objs,method,jstr);

}

