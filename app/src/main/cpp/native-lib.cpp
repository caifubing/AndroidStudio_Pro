#include <jni.h>
#include <string>

#include <exception>
#include <stdexcept>
#include <iostream>
#include <android/log.h>
#include "Demo.h"

#include "string.h"
#include "Poco/Config.h"
#include "Poco/Foundation.h"
#include "Poco/Exception.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/NetException.h"
#include "Poco/NumberFormatter.h"
#include "Poco/Timestamp.h"

using  namespace Poco;

#define TAG "jni_logger"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_c_1digi_pocoexception_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
////1. c++标准库异常
//    try {
//        LOGI("throw 1");
//        throw  1;
//    }catch (...)
//    {
//        LOGI("catch ... throw 1");
//    }
/*
////2. poco 网络异常
    try {
        LOGI("try NetException ...");
        throw Net::NetException();
    }catch (Poco::Exception &e )
    {
        LOGI("cathc NetException ... %s", e.displayText().c_str());
    }
    */

////3. 三方so中抛出c++标准异常
    try{
        LOGI(" try Demo.so Add Func ...");
        int a =  add(4, 6);
        LOGI(" add result:%d", a);
    }catch (...)
    {
        LOGI("catch add ....");
    }


////4. 三方so中抛出poco 网络异常
    try {
       const std::string str = "10.135.129.41:8888";
        Poco::Net::SocketAddress sa;
        Poco::Net::StreamSocket ss;
        LOGI("try Poco socket Address...");
        ss.connect(sa, Poco::Timespan(6, 0));
        LOGI(" try Poco connect ---------");
    }
    catch (Poco::Exception &e)
    {
      std::string str = e.displayText();
      LOGI("catch Poco connect Exception .....%s.", str.c_str());
    }

    return env->NewStringUTF(hello.c_str());
}
