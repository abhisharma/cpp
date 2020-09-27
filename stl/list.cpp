#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void driver_list()
{

// ESSENTIAL FUNCTIONS
    list<int> v1(10);
    list<char> v2(10, 'x');

    for (int i = 0; i < 10; ++i)
        v1.push_back(i);
    v2.push_back('h');
    v2.push_back('e');
    v2.push_front('u');
    v2.push_front('v');

    v1.pop_back();
    v2.pop_back();
    v1.pop_front();
    v2.pop_front();

    cout<<"Size is "<<v1.size()<<" and "<<v2.size()<<endl;
    cout<<"list 1's front and back are "<<v1.front()<<","<<v1.back()<<" and for list 2, front and back are "<<v2.front()<<","<<v2.back()<<endl;

    list<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); ++it)
        cout<<*it<<",";
    cout<<endl;

// OTHER FUNCTIONS
    it = find(v1.begin(), v1.end(), 7);
    v1.insert(it, 99);   //(position, element)
    it = find(v1.begin(), v1.end(), 5);
    v1.erase(it);     //(startpos
    v1.sort();

    cout<<"Max Size is "<<v1.max_size()<<endl;

// Splicing
    list<int> v3(1);
    for (int i = 0; i < 10; ++i)
        v3.push_back(i+44);

    it = find(v1.begin(), v1.end(), 7);
    v1.splice(it, v3);
    for (it = v1.begin(); it != v1.end(); ++it)
        cout<<*it<<",";
    cout<<endl;

}
