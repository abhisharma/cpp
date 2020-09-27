#include <iostream>
#include <utility>

using namespace std;

template <typename T>
class Data {
public:
    Data(const T& t);
    T process();
    ~Data();
private:
    T* d;
};

template <typename T>
Data<T>::Data(const T& t) {
    d = new T();
    *d = t;
}

template <typename T>
Data<T>::~Data() {
    delete d;
}


template <typename T>
T Data<T>::process() {
    cout << *d << endl;
    cout << typeid(*d).name() << endl;
    return *d;
}

template <typename T> using mypair = pair<T, T>;  // template alias

void driver_classtempl() {

    Data<float> d1(3.3);
    d1.process();

    Data<string> d2("hello");
    d2.process();

    mypair<double> p;
    p.first =  100;
    p.second = 200.3;

    cout << p.first << "  "  << p.second << endl;
}