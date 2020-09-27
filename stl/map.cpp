#include <iostream>
#include <map>

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

void driver_map()
{

// ESSENTIAL FUNCTIONS
    map<int, char> s1;
    multimap<char, char*, comp<char> > s2;

    for (int i = 0; i < 10; ++i)
    {
        if (i%2 == 0)
            s1.insert(pair<int, char>(i,'a'));
        else
            s1.insert(pair<int, char>(i,'b'));
    }

    s1[11] = 'c';
    s1[13] = 'f';

    s1.erase(5);

    s2.insert(pair<char, char*>('d', (char*)"yellow"));
    s2.insert(pair<char, char*>('e', (char*)"new"));
    s2.insert(pair<char, char*>('e', (char*)"color"));
    multimap<char, char*>::iterator it3 = s2.insert(pair<char, char*>('e', (char*)"green"));
    s2.erase(it3);
    s2.insert(pair<char, char*>('r', (char*)"red"));


    cout<<"Size is "<<s1.size()<<" and "<<s2.size()<<endl;

    map<int, char>::iterator it;
    for (it = s1.begin(); it != s1.end(); ++it)
        cout<<"("<<(*it).first<<","<<(*it).second<<") ,";
    cout<<endl;

    multimap<char, char*>::iterator it1;
    for (it1 = s2.begin(); it1 != s2.end(); ++it1)
        cout<<"("<<(*it1).first<<","<<(*it1).second<<") ,";
    cout<<endl;

    it = s1.find(4);
    cout<<"Found "<<(*it).first<<" with value "<<(*it).second<<endl;

    it1 = s2.find('e');
    cout<<"Found "<<(*it1).first<<" with value "<<(*it1).second<<" and its count is "<<s2.count('e')<<endl;

// OTHER FUNCTIONS

    it1 = s2.lower_bound('e');
    it3 = s2.upper_bound('e');
    pair<multimap<char, char*>::iterator, multimap<char, char*>::iterator> p = s2.equal_range('e');

    if (p.first == it1 && p.second == it3)
        cout<<"Equal range function works OK"<<endl;

}
