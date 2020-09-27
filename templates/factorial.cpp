#include <iostream>

using namespace std;

template <unsigned long long n>
struct fact {
    enum {v = n*fact<n-1>::v};
};

template<>
struct fact<0> {
    enum {v=1};
};

// trick to print integer result
template<unsigned long long n>
struct X;

void driver_fact()
{
    static_assert(fact<10>::v == 3628800, "Failed fact<10>::v == 3628800");

    constexpr unsigned long long result = fact<15>::v;
    //X<result> x;
}