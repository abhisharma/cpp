#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

// Function Object
template <typename T>
class multipliesFunc
{
public:
    T operator()(const T& t1, const T& t2) const
    {
        return t1*t2;
    }

};

// Function Object for adapters
template <typename T>
class multipliesFunc1 : public binary_function<T,T,bool>
{
public:
    bool operator()(const T& t1, const T& t2) const
    {
        return t1>t2;
    }

};

// Template function
template <typename T>
T accumulate1(typename T::const_iterator& t1, typename T::const_iterator& t2, T& initial, binary_function<T, T, T> f)
{
    for (typename T::const_iterator itr = t1; itr != t2; ++itr)
    {
        initial *= f(*itr);
    }
    return initial;
}

void funcobjects()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(13);

    multipliesFunc<int> m;
    int initial = 1;

    cout<<"Product is "<<accumulate(v.begin(), v.end(), initial, m)<<endl;

    vector<float> v1;
    v1.push_back(3.2);
    v1.push_back(4.3);
    v1.push_back(13.4);

    multipliesFunc1<float> m1;

//    cout<<"Count<4.0 is "<<count_if(v1.begin(), v1.end(), bind1st(m1,4.0))<<endl;
//    cout<<"Count>4.0 is "<<count_if(v1.begin(), v1.end(), bind2nd(m1,4.0))<<endl;
}


