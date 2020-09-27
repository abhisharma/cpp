#include <iostream>

using namespace std;

class cplus
{
private:
    int *data;

public:

// MAGIC THREE

// default constructor
    cplus();
// constructor
    cplus(int);
// destructor
    virtual ~cplus();

// copy constructor
    cplus(const cplus&);

// copy assignment
    virtual cplus& operator=(const cplus&);


// FRIENDS

// stream functions
    friend ostream& operator<<(ostream&, const cplus&);
    friend istream& operator>>(istream&, const cplus&);

};

cplus::cplus()
{
    data = new int;
}

cplus::cplus(int d)
{
    data = new int(d);
}

cplus::~cplus()
{
    delete data;
}

cplus::cplus(const cplus& cp)
{
    data = new int(*(cp.data));
}

cplus& cplus::operator=(const cplus& cp)
{
    if (this != &cp)
    {
        *data = *(cp.data);
    }
    return *this;
}

ostream& operator<<(ostream& s, const cplus& cp)
{
    s << *(cp.data);
    return s;
}

istream& operator>>(istream& s, const cplus& cp)
{
    s >> *(cp.data);
    return s;
}

void driver_cplus()
{
    cplus c;
    cplus c0(6);
    cplus c1 = 5; // because constructor is not explicit
    cplus c2(c1);
    cplus c3;

    c = c0;

    cout<<"Enter data for c3 ";
    c3 =11; //cin>>c3;
    cout<<c<<c0<<c1<<c2<<c3<<endl;
}
