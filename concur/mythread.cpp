#include <iostream>
#include <thread>

using namespace std;
/*
void thread_func(int i, const string& s) {
    cout << "\nInside thread_func " << i <<  endl;
    cout << "s=" << s << endl;
    cout << "thread id=" << this_thread::get_id() << endl;
}

void mythread2() {
    string s2("Hello first thread");
    thread th(thread_func, 30, s2);
    th.join();
}

void mythread() {
    char buffer[1024];
    sprintf(buffer, "%i", 50000);
    string mystr(buffer);

    //thread th(thread_func, 20, cref(mystr));
    thread th2(thread_func, 20, mystr);
    th2.detach();
}*/