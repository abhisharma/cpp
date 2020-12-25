#include <iostream>
#include <string>

using namespace std;

class Foo
{
public:
    static Foo getFoo() { return Foo(); }

    void doSomething(const string&);  // copy version
    void doSomething(string&&);  // move version

    void performSomething(const string&) const;  // const member
    void performSomething(const string&);        // non-const member

    void actSomething(const string&) const &;   // const ref member
    void actSomething(const string&) &&;        // rval ref member

};

void Foo::doSomething(const string& s)
{
    cout << "doSomething(const string& s)" << endl;
}

void Foo::doSomething(string&& s)
{
    cout << "doSomething(string&&)" << endl;
}

void Foo::performSomething(const string& s) const
{
    cout << "performSomething(const string&) const" << endl;
}

void Foo::performSomething(const string& s)
{
    cout << "performSomething(const string&)" << endl;
}

void Foo::actSomething(const string& s) const &
{
    cout << "actSomething(const string&) const &" << endl;
}

void Foo::actSomething(const string& s) &&
{
    cout << "actSomething(const string&) &&" << endl;
}

void driver_rvals()
{
    const Foo cFoo;
    Foo foo;
    string s("yes");

    foo.doSomething(s);
    foo.doSomething("hello");

    foo.performSomething(s);
    cFoo.performSomething(s);

    foo.actSomething(s);
    Foo::getFoo().actSomething(s);
}