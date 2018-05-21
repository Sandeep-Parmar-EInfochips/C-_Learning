#include <thread>
#include <stdio.h>
#include<iostream>
#include <memory>

using namespace std;

void func(int i, double d, const string& s)
{
    cout << i << ", " << d << ", " << s << endl;
}

void func1(int& a)
{
    a++;
}

int main()
{
    thread t(func, 1, 12.50, "sample");
    t.join();

    // passing values by ref.
    int a = 42;
    thread t1(func1, ref(a));
    t1.join();

    cout << a << endl;

    return 0;
}
