#include <iostream>
#include <array>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

void myfunction(string s) {
    cout << '|' << s;
}

struct myclass {
    void operator() (string s) {
        cout << '~' << s;
    }
} myobject;

void driver_arrays() {
    srand(time(nullptr));

    constexpr int mysize = 10;
    array<string, mysize> arr;

    arr.fill("0");

    for (auto s : arr) {  // by value
        cout << ' ' << s;
    }
    cout << endl;

    for (auto& s : arr) {  // by ref
        s =  string(3, 'a' + rand() % arr.size());
    }
    cout << endl;

    for (auto const &s : arr) { // by const ref
        cout << ' ' << s;
    }
    cout << endl;

    // by rvalue ref- only relevant with vector of bools
    vector<bool> v(10);
    // using auto&& so that I can handle the rvalue reference
    //   returned for the vector<bool> case
    for (auto&& e : v)
        e = true;

    // by pointer
    const auto begin = arr.data(); // begin is const string*
    const auto end = arr.data() + arr.size(); // end is also const string*
    for (auto p = begin; p != end; ++p) { // p is const string*
        cout << ' ' << *p;
    }
    cout << endl;

    // by pointer
    const auto* begin2 = arr.data(); // begin2 is const string*
    const auto* end2 = arr.data() + arr.size(); // end2 is also const string*
    for (auto* p = begin2; p != end2; ++p) { // p is const string*
        cout << ' ' << *p;
    }
    cout << endl;

    /**************************************************/

    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        cout << "arr[" << it-arr.cbegin() << "] = " << *it <<endl;
    }

    for_each (arr.begin(), arr.end(), myfunction);
    cout << endl;
    for_each (arr.begin(), arr.end(), myobject);
    cout << endl;

    cout << "Array is " << (arr.empty() ? "empty" : "not empty") << endl;
    cout << "Array front is " << arr.front() << endl;
    cout << "Array back is " << arr.back() << endl;
}

/*    The const qualifier applies to the type to the immediate left unless there is nothing to the left then
    it applies to the type to the immediate right.
Choose auto x when you want to work with copies.
Choose auto &x when you want to work with original items and may modify them.
Choose auto const &x when you want to work with original items and will not modify them.
 */