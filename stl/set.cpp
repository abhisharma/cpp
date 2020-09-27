#include <iostream>
#include <set>

using namespace std;

template <typename T>
class comp
{
public:
    bool operator()(const T& x, const T& y) const
    {
        return y<x;
    }
};

void driver_set()
{

// ESSENTIAL FUNCTIONS
    set<int> s1;
    multiset<char, comp<char> > s2;

    for (int i = 0; i < 10; ++i)
        s1.insert(i);

    s1.erase(5);

    s2.insert('d');
    s2.insert('e');
    s2.insert('e');
    multiset<char>::iterator it3 = s2.insert('e');
    s2.erase(it3);
    s2.insert('r');


    cout<<"Size is "<<s1.size()<<" and "<<s2.size()<<endl;

    set<int>::iterator it;
    for (it = s1.begin(); it != s1.end(); ++it)
        cout<<*it<<",";
    cout<<endl;

    multiset<char>::iterator it1;
    for (it1 = s2.begin(); it1 != s2.end(); ++it1)
        cout<<*it1<<",";
    cout<<endl;

    it = s1.find(4);
    cout<<"Found "<<*it<<endl;

// OTHER FUNCTIONS

    it1 = s2.lower_bound('e');
    it3 = s2.upper_bound('e');
    pair<multiset<char>::iterator, multiset<char>::iterator> p = s2.equal_range('e');

    if (p.first == it1 && p.second == it3)
        cout<<"Equal range function works OK"<<endl;

}
