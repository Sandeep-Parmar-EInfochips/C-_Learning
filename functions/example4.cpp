#include <functional>
#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;
using namespace std::placeholders;

class Test
{
public:
    Test(int _x)
    {
        x = _x;
    }

    int func1(int _y)
    {
        return _y;
    }

    int func2(int val)
    {
        return val + x;
    }

private:
    int x;
};


int main()
{
    Test foo(32);
    std::function<int (int)> f = [](int i)->int{ return i; } ;
    std::function<int ()> g = [&foo]()->int{ return foo.func2(10); };

    assert( (f(10) + g()) == 52);
    return 0;
}
