/*
 * std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
 * Several shared_ptr objects may own the same object.
 * The object is destroyed and its memory deallocated when either of the following happens:
 *     the last remaining shared_ptr owning the object is destroyed;
 *     the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().
 *
 * The object is destroyed using delete-expression or a custom deleter that is supplied to shared_ptr during construction.
 *
 * A shared_ptr can share ownership of an object while storing a pointer to another object.
 * This feature can be used to point to member objects while owning the object they belong to.
 * The stored pointer is the one accessed by get(), the dereference and the comparison operators.
 * The managed pointer is the one passed to the deleter when use count reaches zero.
 *
 * A shared_ptr may also own no objects,
 * in which case it is called empty (an empty shared_ptr may have a non-null
 * stored pointer if the aliasing constructor was used to create it).
 *
 * All specializations of shared_ptr meet the requirements of CopyConstructible,
 * CopyAssignable, and LessThanComparable and are contextually convertible to bool.
 *
 * All member functions (including copy constructor and copy assignment)
 * can be called by multiple threads on different instances of shared_ptr without
 * additional synchronization even if these instances are copies and share ownership of the same object.
 * If multiple threads of execution access the same shared_ptr without synchronization
 * and any of those accesses uses a non-const member function of shared_ptr
 * then a data race will occur; the shared_ptr overloads of atomic functions can be used to prevent the data race.
 */

#include <stdio.h>
#include<iostream>
#include <memory>
using namespace std;

class Foo {
public:
    Foo() { cout << "Foo..." << endl; }
    ~Foo() { cout << "~Foo..." << endl; }
};

class FooDelete {
public:
    void operator()(Foo* p) const {
        cout << "Call delete from function object..." << endl;
        delete p;
    }
};

int main()
{
    cout << "constructor with no managed object\n";
    shared_ptr<Foo> sh1;
    cout << sh1.use_count() << endl;

    cout << "constructor with object\n";
    shared_ptr<Foo> sh2(new Foo);
    shared_ptr<Foo> sh3(sh2);
    cout << sh2.use_count() << endl;
    cout << sh3.use_count() << endl;

    cout << "constructor with object and deleter\n";
    shared_ptr<Foo> sh4(new Foo, FooDelete());
    shared_ptr<Foo> sh5(new Foo, [](Foo *p) {cout << "Call delete from lambda..." << endl; delete p;});
    cout << sh4.use_count() << endl;
    cout << sh5.use_count() << endl;
}
