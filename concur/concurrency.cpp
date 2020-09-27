#include <iostream>
#include <future>

using namespace std;
/*
long myfunc() {
    const long MAX_COUNT = 1000000000;
    auto s = 0;
    for (auto i = 0; i <= MAX_COUNT; ++i) {
        s += i*i;
    }
    return s;
}

long myfunc2(long limit) {
    auto s = 0;
    for (auto i = 0; i <= limit; ++i) {
        s += i*i;
    }
    return s;
}

void concurrency() {
    future<long> f = async(myfunc);
    cout<<"Sum is "<<f.get()<<endl;
    
    // with arguments and using lambda
    auto f2  = async(myfunc2, 1000);
    auto f3 = async([]{return myfunc2(2000);});
    
    cout<<"Sum is "<<f2.get()<<endl;
    cout<<"Sum is "<<f3.get()<<endl;
    
    // Shared futures can call get more than once    
    shared_future<long> f4 = async(myfunc2, 3000);
    cout<<"Sum is "<<f4.get()<<endl;
    cout<<"Sum is "<<f4.get()<<endl;
    
    auto f5 = async(myfunc2, 4000).share();
    cout<<"Sum is "<<f5.get()<<endl;
    cout<<"Sum is "<<f5.get()<<endl;
    
}
*/