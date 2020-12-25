#include <iostream>
#include <string_view>

using namespace std;

void driver_stringview()
{
    string s{"Hello world"};
    string_view sv{s};

    sv.remove_prefix(2);
    sv.remove_suffix(1);

    cout << sv << endl;

    cout << strlen(sv.data()) << endl;

    string s2{sv};

    cout << s2 << endl;
}

