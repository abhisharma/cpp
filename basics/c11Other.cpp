#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2>
auto add(const T1& x, const T2& y) -> decltype(x+y)
{
    return x+y;
}

template <typename T1, typename T2>
decltype(auto) add2(const T1& x, const T2& y)
{
    return x+y;
}

template <typename T1, typename T2, typename... T3>
void print(const T1& x, const T2& y, const T3&... z)
{
    cout << sizeof...(z) <<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}

template<typename T>
class TD
{};

void c112()
{
    cout<<"############"<<endl;
    cout << add<int,float>(4,9.8) <<endl;
    cout << add2<int,float>(4,9.8) <<endl;
    
    vector<int> v;
    
    decltype(v)::iterator it = v.begin();
    auto it2 = v.end();
    
    cout<<(it == it2) <<endl;
    
    print(9.5,11,"abc", "def");

}

void c113()
{
    const int ci = 2;
    const int &cj = ci;
    auto a = ci;
    auto b = &ci;
    auto c = cj;   // I don't understand because cj is reference to const int. Hence Low level const.
    TD<decltype(a)> aa;
    TD<decltype(b)> bb;
    TD<decltype(c)> cc;
}

