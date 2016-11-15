#include "xd_dl_job_ParkNative.h"

JNIEXPORT jint JNICALL Java_xd_dl_job_ParkNative_initialized
  (JNIEnv *env, jclass cls, jstring a, jstring b, jstring c, jstring d){
  	return 0;
  }

/*
 * Class:     xd_dl_job_ParkNative
 * Method:    unitialized
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_xd_dl_job_ParkNative_unitialized
  (JNIEnv *env, jclass cls){
  	return 0;
  }

/*
 * Class:     xd_dl_job_ParkNative
 * Method:    getParkedCarInfo
 * Signature: (ILjava/lang/String;IZI)Lxd/dl/job/ParkedCarInfo;
 */
JNIEXPORT jobject JNICALL Java_xd_dl_job_ParkNative_getParkedCarInfo
  (JNIEnv *env, jclass cls, jint car_type, jstring car_license
  , jint freetime, jboolean bFuzzyMatch, jint carOrder){
  	
  	jclass objcls = env->FindClass("xd/dl/job/ParkedCarInfo");
    jobject obj = env->AllocObject(objcls);
    
    jfieldID str = (env)->GetFieldID(objcls,"sInTime","Ljava/lang/String;");
	jfieldID strCarLicense = (env)->GetFieldID(objcls,"sCarLicense","Ljava/lang/String;");
	jfieldID strInPic = (env)->GetFieldID(objcls,"sInPic","Ljava/lang/String;");
	jfieldID iParkedTimeVal = (env)->GetFieldID(objcls,"iParkedTime","I");
	jfieldID iReturnVal = (env)->GetFieldID(objcls,"iReturn","I");
	jfieldID fMoneyVal = (env)->GetFieldID(objcls,"fMoney","F");
	
	(env)->SetObjectField(obj,str,env->NewStringUTF("2017-10-10 00:00:001"));
	(env)->SetObjectField(obj,strCarLicense,env->NewStringUTF("?A12345"));
	
	char *path = new char[100];
	sprintf(path, "C:\\Work\\C++\\ParkingMeter\\%d.png",carOrder);
	
	(env)->SetObjectField(obj,strInPic,env->NewStringUTF(path));
	(env)->SetIntField(obj,iParkedTimeVal,162);
	(env)->SetIntField(obj,iReturnVal,0);
	(env)->SetFloatField(obj,fMoneyVal,0.01f);
	
	return obj;
  }
  

/*
 * Class:     xd_dl_job_ParkNative
 * Method:    payParkCarFee
 * Signature: (ILjava/lang/String;Ljava/lang/String;F)I
 */
JNIEXPORT jint JNICALL Java_xd_dl_job_ParkNative_payParkCarFee
  (JNIEnv *env, jclass cls, jint car_type, jstring car_license, jstring pay_time, jfloat fee){
  	return 0;
  }
