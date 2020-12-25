#include <iostream>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

list<int> some_list;
mutex some_mutex;

void addToList(int i) {
    lock_guard<mutex> guard(some_mutex);
    some_list.push_back(i);
}

bool containsList(int i) {
    lock_guard<mutex> guard(some_mutex);
    return find(some_list.begin(), some_list.end(), i) != some_list.end();
}

void thread_func(int i) {
    cout << "\nInside thread_func " << i <<  endl;
    cout << "\nthread id=" << this_thread::get_id() << endl;
    addToList(i);
    cout << "\ncontainsList(" << i << ")=" << containsList(i) << endl;
}

class X {
    int data;
    mutex m;
public:
    X(int i) : data(i) {}

    void print() {
        cout << "Data is " << data << endl;
    }
    friend void swap(X& lhs, X& rhs) {
        if (&lhs == &rhs) {
            return;
        }
        unique_lock<mutex> lock_a(lhs.m, defer_lock);
        unique_lock<mutex> lock_b(rhs.m, defer_lock);
        lock(lock_a, lock_b);

        swap(lhs.data, rhs.data);
    }
};

void concurrency2() {
    thread th(thread_func, 1);
    th.detach();

    thread th2(thread_func, 2);
    th2.detach();

    X x1(1), x2(2);
    swap(x1, x2);
    x1.print();
    x2.print();
}
