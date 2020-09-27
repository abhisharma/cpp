#include <iostream>
#include <type_traits>

using namespace std;

/*
 * template< class T, T v >
struct integral_constant;

true_type	std::integral_constant<bool, true>
false_type	std::integral_constant<bool, false>
 *
 * */

template<typename T>   // primary template
struct is_void_type : false_type
{
};

template<>  // explicit specialization for T = void
struct is_void_type<void> : true_type
{
};


void driver_special()
{
    cout << is_void_type<char>::value << endl;
    cout << is_void_type<void>::value << endl;
}