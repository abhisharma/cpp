#include <iostream>
#include <functional>

using namespace std;

int64_t  divide(float a, float b) {
    return static_cast<int64_t>(a/b);
}

template<typename T>
bool bigger(T t1, T t2) {
    return t1 > t2;
}

void driver_functempl()
{
    // function templates//////////////////////////////////////////////////////
    cout << bigger<int>(2,3) << endl;
    cout << bigger<int>(3,2) << endl;


    // functional//////////////////////////////////////////////////////
    function<int64_t (float, float) > func = &divide;
    function<int64_t (float, float) > func1 = bind(divide, placeholders::_2, placeholders::_1);
    function<int64_t (float) > func2 = bind(divide, placeholders::_1, 20);


    cout <<"Functional" << endl;
    cout<<func(7, 3) <<endl;
    cout<<func1(7, 30) <<endl;
    cout<<func2(100) <<endl;

    // Lambdas///////////////////////////////////////////////////////////////////

    auto func3 = [](int x){ return x*x; };
    function<int (int) > func4 = [&func4](int n)
    {
        return n <= 1 ? 1  : n * func4(n-1);
    };


    cout<<func3(7) <<endl;
    cout<<[](int x){ return x*x; }(7) <<endl;
    cout<<func4(6) <<endl;

    cout<<"###################"<<endl;
    int x = 1;
    [=]() mutable { cout << ++x << endl; }();  // 2
    cout << x << endl;   //1
    [&](){ cout << ++x << endl; }(); //2
    cout << x << endl; // 2

    cout<<"###################"<<endl;
    auto rlambda = [](int x) -> double { return x*x/2.0; };
    cout << rlambda(5) << endl;
}