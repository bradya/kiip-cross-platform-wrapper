/*-
*  Cross-Platform C++ Wrapper for Kiip
*  Designed to work with iOS and Android Kiip libraries
*  http://kiip.me
*  
*  Created by Brady Archambo (in no way affiliated with Kiip)
*
*  Find me on Twitter, twitter.com/bradyy
*
*/

#include <android/log.h>
#include <jni.h>
#include <cstring>

#include "Kiip_android.h"
 
#define  LOG_TAG    "Kiip_Android Debug"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


KiipWrapper* KiipWrapper::m_spKiipWrapper = NULL;
JavaVM* m_spJavaVM = NULL;


KiipWrapper* KiipWrapper::sharedKiipWrapper()
{
    if (m_spKiipWrapper == NULL) {
        m_spKiipWrapper = new KiipWrapper();
    }
    
    return m_spKiipWrapper;
}


jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    m_spJavaVM = vm;
    return JNI_VERSION_1_4;
}


// Assigns JNIEnv to pointer argument
static bool getEnv(JNIEnv **env)
{
    bool bRet = false;
    
    do 
    {
        if (m_spJavaVM->GetEnv((void**)env, JNI_VERSION_1_4) != JNI_OK)
        {
            LOGD("Failed to get the environment using GetEnv()");
            break;
        }
        
        if (m_spJavaVM->AttachCurrentThread(env, 0) < 0)
        {
            LOGD("Failed to get the environment using AttachCurrentThread()");
            break;
        }
        
        bRet = true;
    } while (0);		
    
    return bRet;
}


// Unlocks an achievement in Kiip
// Android JNI (Java Native Interface) method
void KiipWrapper::unlockAchievement(const char * name)
{
    LOGD("Unlock achievement");
    
    // Get JNI environment
    JNIEnv *env = 0;
    
    if (! getEnv(&env))
    {
        return;
    }
    
    LOGD("Got env");
    
    // Get KPManager class
    jclass classID = env->FindClass("me/kiip/api/KPManager");
    
    if (! classID)
    {
        return;
    }
    
    if(env->ExceptionCheck()) {    // ClassNotFoundException ?
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    
    LOGD("Got KPManager class");
    
    // Get 'getInstance' method
    jmethodID getInstanceMethod = env->GetStaticMethodID(classID, "getInstance", "()Lme/kiip/api/KPManager;");
    
    if (!getInstanceMethod)
    {
        return;
    }
    
    LOGD("Got getInstance Method");
    
    // Call 'getInstance' method
    jobject manager = env->CallStaticObjectMethod(classID, getInstanceMethod);
    
    if (! manager)
    {
        return;
    }
    
    LOGD("Got manager");
    
    // Get class of manager
    // Redundant, but had issues getting it to work otherwise
    jclass cls = env->GetObjectClass(manager);
    
    if (! cls)
    {
        return;
    }
    
    if(env->ExceptionCheck()) {    // ClassNotFoundException ?
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    
    LOGD("Got class of manager");
    
    // Get 'unlockAchievement' method
    jmethodID method = env->GetMethodID(cls, "unlockAchievement", "(Ljava/lang/String;Lme/kiip/api/KPManager$KPRequestListener;[Ljava/lang/String;)V");
    
    if (! method)
    {
        return;
    }
    
    LOGD("Got unlock achievement method");
    
    // Create string with achievement name parameter
    jstring achievementName = env->NewStringUTF(name);
    
    if (! achievementName)
    {
        return;
    }
    
    LOGD("Made achievement name");
    
    // Pass in tags to the method
    // Passing in null was failing
    // TODO: Move these to an arg
    char *data[2]= {"A", "B"};
    
    jobjectArray ret = (jobjectArray)env->NewObjectArray(2,env->FindClass("java/lang/String"),env->NewStringUTF(""));
    
    for(int i = 0; i < 2 ;i++) {
        env->SetObjectArrayElement(ret,i,env->NewStringUTF(data[i]));
    }
    
    // Call 'unlockAchievement' with achievement name and tags
    env->CallVoidMethod(manager, method, achievementName, NULL, ret);
    
    LOGD("Called unlockAchievement");
}

void KiipWrapper::reportScoreForLeaderboard(const char * name, double score)
{
    LOGD("Report score for leaderboard");
    
    // Get JNI environment
    JNIEnv *env = 0;
    
    if (! getEnv(&env))
    {
        return;
    }
    
    LOGD("Got env");
    
    // Get KPManager class
    jclass classID = env->FindClass("me/kiip/api/KPManager");
    
    if (! classID)
    {
        return;
    }
    
    if(env->ExceptionCheck()) {    // ClassNotFoundException ?
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    
    LOGD("Got KPManager class");
    
    // Get 'getInstance' method
    jmethodID getInstanceMethod = env->GetStaticMethodID(classID, "getInstance", "()Lme/kiip/api/KPManager;");
    
    if (!getInstanceMethod)
    {
        return;
    }
    
    LOGD("Got getInstance Method");
    
    // Call 'getInstance' method
    jobject manager = env->CallStaticObjectMethod(classID, getInstanceMethod);
    
    if (! manager)
    {
        return;
    }
    
    LOGD("Got manager");
    
    // Get class of manager
    // Redundant, but had issues getting it to work otherwise
    jclass cls = env->GetObjectClass(manager);
    
    if (! cls)
    {
        return;
    }
    
    if(env->ExceptionCheck()) {    // ClassNotFoundException ?
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    
    LOGD("Got class of manager");
    
    // Get 'saveLeaderboard' method
    jmethodID method = env->GetMethodID(cls, "saveLeaderboard", "(Ljava/lang/String;ILme/kiip/api/KPManager$KPRequestListener;[Ljava/lang/String;)V");
    
    if (! method)
    {
        return;
    }
    
    LOGD("Got save leaderboard method");
    
    // Create string with leaderboard name parameter
    jstring leaderboardName = env->NewStringUTF(name);
    
    if (! leaderboardName)
    {
        return;
    }
    
    LOGD("Made leaderboard name");
    
    // Pass in tags to the method
    // Passing in null was failing
    // TODO: Move these to an arg
    char *data[2]= {"A", "B"};
    
    jobjectArray ret = (jobjectArray)env->NewObjectArray(2,env->FindClass("java/lang/String"),env->NewStringUTF(""));
    
    for(int i=0; i<2 ;i++) {
        env->SetObjectArrayElement(ret,i,env->NewStringUTF(data[i]));
    }
    
    LOGD("Made string array");
    
    // Convert score to JNI compatible integer
    jint convertedScore = (jint) score;
    
    // Call 'saveLeaderboard' method with leaderboard name, score, and tags
    env->CallVoidMethod(manager, method, leaderboardName, convertedScore, NULL, ret);
    
    LOGD("Called saveLeaderboard");
}