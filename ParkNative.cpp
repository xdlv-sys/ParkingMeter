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
	jfieldID strId = (env)->GetFieldID(objcls,"sID","Ljava/lang/String;");
	jfieldID strInPic = (env)->GetFieldID(objcls,"sInPic","Ljava/lang/String;");
	jfieldID iParkedTimeVal = (env)->GetFieldID(objcls,"iParkedTime","I");
	jfieldID iReturnVal = (env)->GetFieldID(objcls,"iReturn","I");
	jfieldID fMoneyVal = (env)->GetFieldID(objcls,"fMoney","F");
	
	(env)->SetObjectField(obj,str,env->NewStringUTF("2017-10-10 00:00:001"));
	

	if (carOrder != 3){
		char *path = new char[8];
	    sprintf(path, "%d.jpg",carOrder);
	    (env)->SetObjectField(obj,strInPic,env->NewStringUTF(path));
	}
	
	
	char *license = new char[8];
	sprintf(license,"HA1234%d",carOrder);
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
  		(env)->SetObjectField(obj,strParkName,env->NewStringUTF("WO_DE"));
		(env)->SetIntField(obj,iSumNum,100);
		(env)->SetIntField(obj,iLeftNum,50);
		(env)->SetIntField(obj,iCarProp,i + 1);
  		(env)->SetObjectArrayElement(rets, i, obj);
	}
  	
  	return rets;
  } 
  
  JNIEXPORT jobjectArray JNICALL Java_xd_dl_job_ParkNative_getCarportInfo
  (JNIEnv *env, jclass cls, jstring car_number){
  	
  	jclass objcls = env->FindClass("xd/dl/job/ViewCarportRoomInfo");
  	
  	jfieldID sCarportNum = (env)->GetFieldID(objcls,"sCarportNum","Ljava/lang/String;");
  	jfieldID sRoomNum = (env)->GetFieldID(objcls,"sRoomNum","Ljava/lang/String;");
  	jfieldID sName = (env)->GetFieldID(objcls,"sName","Ljava/lang/String;");
  	jfieldID sAddress = (env)->GetFieldID(objcls,"sAddress","Ljava/lang/String;");
  	jfieldID sPhoneNumber = (env)->GetFieldID(objcls,"sPhoneNumber","Ljava/lang/String;");
  	jfieldID sPosition = (env)->GetFieldID(objcls,"sPosition","Ljava/lang/String;");
  	jfieldID sStartDate = (env)->GetFieldID(objcls,"sStartDate","Ljava/lang/String;");
  	jfieldID sEndDate = (env)->GetFieldID(objcls,"sEndDate","Ljava/lang/String;");  	
	jfieldID fDeposit = (env)->GetFieldID(objcls,"fDeposit","F");
	jfieldID bTemporary = (env)->GetFieldID(objcls,"bTemporary","Z");
	jfieldID sRemark = (env)->GetFieldID(objcls,"sRemark","Ljava/lang/String;");
	jfieldID sRentName = (env)->GetFieldID(objcls,"sRentName","Ljava/lang/String;");
	jfieldID fRentMoney = (env)->GetFieldID(objcls,"fRentMoney","F");
	jfieldID sParkName = (env)->GetFieldID(objcls,"sParkName","Ljava/lang/String;");
	
  	jobjectArray rets = env->NewObjectArray(3,objcls,NULL);
  	for (int i=0;i<3;i++){
  		jobject obj = env->AllocObject(objcls);
  		(env)->SetObjectField(obj,sCarportNum,env->NewStringUTF("sCarportNum" + i));
  		(env)->SetObjectField(obj,sRoomNum,env->NewStringUTF("sRoomNum" + i));
  		(env)->SetObjectField(obj,sName,env->NewStringUTF("sName" + i));
  		(env)->SetObjectField(obj,sAddress,env->NewStringUTF("sAddress" + i));
  		(env)->SetObjectField(obj,sPhoneNumber,env->NewStringUTF("sPhoneNumber" + i));
  		(env)->SetObjectField(obj,sPosition,env->NewStringUTF("sPosition" + i));
  		(env)->SetObjectField(obj,sStartDate,env->NewStringUTF("2016-1-1"));
  		(env)->SetObjectField(obj,sEndDate,env->NewStringUTF("2016-12-31"));
  		(env)->SetFloatField(obj,fDeposit,0.01);
  		(env)->SetBooleanField(obj,bTemporary, i == 0);
  		(env)->SetObjectField(obj,sRemark,env->NewStringUTF("sRemark" + i));
  		(env)->SetObjectField(obj,sRentName,env->NewStringUTF("sRentName" + i));
  		(env)->SetFloatField(obj,fRentMoney,0.01 * (i + 1));
  		(env)->SetObjectField(obj,sParkName,env->NewStringUTF("sParkName" + i));
		
  		(env)->SetObjectArrayElement(rets, i, obj);
	}
  	
  	return rets;
  	
  }

/*
 * Class:     xd_dl_job_ParkNative
 * Method:    payCarportRent
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;IFZ)I
 */
JNIEXPORT jint JNICALL Java_xd_dl_job_ParkNative_payCarportRent
  (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring, jint, jfloat, jboolean){
  	return 0;
  }
