#include <iostream>
#include <memory>

using namespace std;

struct D {
    D() { std::cout << "D::D\n";  }
    ~D() { std::cout << "D::~D\n";  }
    void bar()  { std::cout << "D::bar\n"; }
};

void driver_smartptrs()
{
    // UNIQUE
    unique_ptr<D> p = make_unique<D>();
    p->bar();

    // SHARED
    shared_ptr<D> sp = make_shared<D>();
    sp->bar();

    // WEAK
    shared_ptr<D> sp2;
    weak_ptr<D> wp(sp);

    if ((sp2 = wp.lock())) {
        sp2->bar();
    }
    else {
        cout << "Shared ptr is expired";
    }
}