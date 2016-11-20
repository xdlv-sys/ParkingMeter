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
  , jint freetime, jint bFuzzyMatch, jint carOrder,jstring sSearchID, jstring sSearchInTime){
  	
  	jclass objcls = env->FindClass("xd/dl/job/ParkedCarInfo");
    jobject obj = env->AllocObject(objcls);
    
    jfieldID str = (env)->GetFieldID(objcls,"sInTime","Ljava/lang/String;");
	jfieldID strCarLicense = (env)->GetFieldID(objcls,"sCarLicense","Ljava/lang/String;");
	jfieldID strId = (env)->GetFieldID(objcls,"sId","Ljava/lang/String;");
	jfieldID strInPic = (env)->GetFieldID(objcls,"sInPic","Ljava/lang/String;");
	jfieldID iParkedTimeVal = (env)->GetFieldID(objcls,"iParkedTime","I");
	jfieldID iReturnVal = (env)->GetFieldID(objcls,"iReturn","I");
	jfieldID fMoneyVal = (env)->GetFieldID(objcls,"fMoney","F");
	
	(env)->SetObjectField(obj,str,env->NewStringUTF("2017-10-10 00:00:001"));
	
	char *path = new char[8];
	sprintf(path, "%d.jpg",carOrder);
	(env)->SetObjectField(obj,strInPic,env->NewStringUTF(path));
	
	char *license = new char[8];
	sprintf(license,"ËÕA1234%d",carOrder);
	(env)->SetObjectField(obj,strCarLicense,env->NewStringUTF(license));
	
	char *sid = new char[8];
	sprintf(sid,"%d",carOrder + 100);
	(env)->SetObjectField(obj,strId,env->NewStringUTF(sid));
	
	(env)->SetIntField(obj,iParkedTimeVal,162);
	
	(env)->SetIntField(obj,iReturnVal,carOrder > 3 ? 11 : 0);
	(env)->SetFloatField(obj,fMoneyVal,0.01f);
	
	return obj;
  }
  

/*
 * Class:     xd_dl_job_ParkNative
 * Method:    payParkCarFee
 * Signature: (ILjava/lang/String;Ljava/lang/String;F)I
 */
JNIEXPORT jint JNICALL Java_xd_dl_job_ParkNative_payParkCarFee
  (JNIEnv *env, jclass cls, jint car_type, jstring car_license, jstring pay_time, jfloat fee,jstring sID, jstring sInTime, jint iPayMethod){
  	return 0;
  }
  
JNIEXPORT jobjectArray JNICALL Java_xd_dl_job_ParkNative_getLeftParkInfo
  (JNIEnv *env, jclass cls){
  	jclass objcls = env->FindClass("xd/dl/job/LeftParkInfo");
  	jfieldID strParkName = (env)->GetFieldID(objcls,"sParkName","Ljava/lang/String;");
	jfieldID iSumNum = (env)->GetFieldID(objcls,"iSumNum","I");
	jfieldID iLeftNum = (env)->GetFieldID(objcls,"iLeftNum","I");
	jfieldID iCarProp = (env)->GetFieldID(objcls,"iCarProp","I");
	
  	jobjectArray rets = env->NewObjectArray(2,objcls,NULL);
  	for (int i=0;i<2;i++){
  		jobject obj = env->AllocObject(objcls);
  		(env)->SetObjectField(obj,strParkName,env->NewStringUTF("ÄÏ¾©De"));
		(env)->SetIntField(obj,iSumNum,100);
		(env)->SetIntField(obj,iLeftNum,50);
		(env)->SetIntField(obj,iCarProp,i + 1);
  		(env)->SetObjectArrayElement(rets, i, obj);
	}
  	
  	return rets;
  } 
