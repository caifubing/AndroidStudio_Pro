#include <jni.h>
#include <string>

#include <exception>
#include <stdexcept>
#include <iostream>

#include "Poco/Config.h"
#include "Poco/Foundation.h"
#include "Poco/Exception.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/NetException.h"

using  namespace Poco;

using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_c_1digi_pocoexception_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    cout << "Test Exception: " << endl;
    //double m, n;
    //cin >> m >> n;
    try {
        //cout << "before dividing." << endl;
        //if (n == 0)
        //	throw - 1; //抛出int类型异常
        //else
        //	cout << m / n << endl;

       const std::string str = "10.135.129.41:8888";
        Poco::Net::SocketAddress sa;
        std::cout << " test connect ----------adsf" << std::endl;
        Poco::Net::StreamSocket ss;
       // std::cout << " test connect ----------111" << std::endl;
        ss.connect(sa, Poco::Timespan(6, 0));
        //std::cout << "test " << ss.available();
        std::cout << " test connect ----------2222" << std::endl;

        cout << "after dividing." << endl;
    }
    catch (double d) {
        cout << "catch(double) " << d << endl;
    }
    catch (int e) {
        cout << "catch(int) " << e << endl;
    }
    catch (...)
    {
        std::cout << "catch ..................EEEEEEEEEEE" << std::endl;
    }
    cout << "finished" << endl;

    return env->NewStringUTF(hello.c_str());
}
