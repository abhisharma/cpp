#include<iostream>

using namespace std;

int g_arr[] = {1,8,27,64,125};

// Parameter is reference to array
template<size_t N>
void f1(int (&arr)[N])
{
    cout<<arr[3]<<endl;
}

// Return type is reference to array
template<size_t N>
int (&f11())[N]
{
    return g_arr;
}

// Parameter is pointer to array
template<size_t N>
void f2(int (*arr)[N])
{
    cout<<(*arr)[3]<<endl;
}

// Return type is pointer to array
template<size_t N>
int (*f22())[N]
{
    return &g_arr;
}

void arrayrefs(){
    const int N = 5;
    int buf[N] = {1,2,3,4,5};
    int buf2[] = {1,4,9,16,25};

    cout <<"#########"<<endl;
    f1(buf);   // Ref to array
    f2(&buf2);  // Pointer to array

    int (&arr)[N] = f11<N>();  // Ref to array
    int (*arr2)[N] = f22<N>();  // Pointer to array

    cout<<arr[3]<<endl;
    cout<<(*arr2)[4]<<endl;
}