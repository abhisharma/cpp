
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void tuples()
{
    tuple<int, string> t1(2, "hello");
    tuple<int, string> t2{2, "hello"};
    tuple<int, string> t3 = make_tuple(3,"yes");

    int x = get<0>(t1);
    string y = get<1>(t2);
    tie(ignore, y) = t3;

    cout<<x<<endl;
    cout<<y<<endl;

}

void enums()
{
    cout<<"############"<<endl;

    enum class Alert { green, yellow, red };
    enum class Color : int{red, green, blue};

    cout<<static_cast<int>(Alert::yellow)<<endl;
    cout<<static_cast<int>(Color::green)<<endl;
    underlying_type<Color>::type enumValue;

    cout.setf(ios::boolalpha);
    cout  << "issame " << is_same<underlying_type<Color>::type, int>() << endl;
}

void forloop()
{
    int arr[] = {1,2,3,4,5,6};
    for (auto i : arr) {
        cout << i << endl;
    }
    cout<<*begin(arr)<<"\t"<<*(end(arr)-1)<<endl;
    
    /***************************/
    
    vector<string> vec{"abc", "def"};
    
    for (const auto& elem : vec) {
        cout<<elem<<endl;
    }
}

class P {
public:
    P(int x, int y) : _x(x), _y(y) {}
    explicit P(initializer_list<int> l) {
        for (int x : l) {
            _x = x;
        }
        _y = 0;
    }
    
private:
    int _x, _y;
};

void init() {
    int x{};
    int* ptr{};
    //int y{5.5};
    int myarr[]{1,2,3,4,5};
    
    cout<<myarr[0]<<endl;
    
    if (x==0){
        cout<<"x is 0"<<endl;
    }
    if (ptr==nullptr){
        cout<<"ptr is null"<<endl;
    }
    
    P p(1,2);
    P p1{1,2};
   // P p2 = {1,2};
    P p3{1,2,3};
   // P p4 = {1,2,3};
}


void c11()
{
    cout<<"############"<<endl;
    tuples();
    enums();
    forloop();
    init();
}
