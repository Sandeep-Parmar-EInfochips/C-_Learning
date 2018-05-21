#include <stdio.h>
#include<iostream>
using namespace std;
void myfunc(int x)
{
    cout << "x value is :" << x << endl;
}

int main()
{
    void (*foo)(int);
    void (*foo1)(int);

    /* the ampersand is actually optional */
    foo = &myfunc;
    foo1 = myfunc;

    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );


    foo1( 4 );
    (*foo1)( 4 );

    return 0;
}
