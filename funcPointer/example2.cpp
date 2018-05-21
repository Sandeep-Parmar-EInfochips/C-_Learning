#include <iostream>
#include <string>
#include <stdio.h>
#include <memory>
using std::string;
using namespace std;

class Foo{
public:
  int f(string str){
    cout<<"Foo::f()"<<  endl;
    return 1;
  }

  int f1(int x, int y){
    cout<<" x is : " << x << " y is :" << y <<  endl;
    return (x+y);
  }

  static int f3(string str){
    std::cout<<"static f3 "<<std::endl;
    return 1;
  }
};

int main()
{
  int (Foo::*fptr) (string) = &Foo::f;

  int (Foo::*fptr1) (int,int) = &Foo::f1;

  Foo obj;
  (obj.*fptr)("str");//call: Foo::f() through an object
  cout << (obj.*fptr1)(1,2) << endl;


  Foo* p=&obj;
  (p->*fptr)("str");//call: Foo::f() through a pointer
  cout << (p->*fptr1)(3,4) << endl;


  int (*fptr3) (string) = &Foo::f3;
  (*fptr3)("str3");//call Foo::f3()


  return 0;
}
