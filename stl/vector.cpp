#include <iostream>
#include <vector>

using namespace std;

void driver_vector()
{

// ESSENTIAL FUNCTIONS
    vector<int> v1(10);
    vector<char> v2(10, 'x');

    for (int i = 0; i < 10; ++i)
        v1.push_back(i);
    v2.push_back('h');
    v2.push_back('e');

    v1.pop_back();
    v2.pop_back();

    cout<<"Size is "<<v1.size()<<" and "<<v2.size()<<endl;
    cout<<"Vector 1's front and back are "<<v1.front()<<","<<v1.back()<<" and for vector 2, front and back are "<<v2.front()<<","<<v2.back()<<endl;

    v2[2] = 's';
    v1[2] = 100;
    cout<<"3rd element in vector 1 and 2 is "<<v1[2]<<" and "<<v2[2]<<endl;

    vector<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); ++it)
        cout<<*it<<",";
    cout<<endl;

// OTHER FUNCTIONS
    v1.insert(v1.begin()+3,99);   //(position, element)
    v1.erase(v1.begin()+7,v1.begin()+9);     //(startpos, endpos)


    cout<<"Max Size is "<<v1.max_size()<<endl;
    cout<<"Capacity is "<<v1.capacity()<<endl;

}
