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

    int func2()
    {
        return x;
    }


private:
    int x;
};


int main()
{
    Test t1(25);

    function< int (int)> f1 = bind(&Test::func1,t1,_1);
    function< int ()> f2 = bind(&Test::func2,t1);

    assert((f1(10) + f2()) == 35 );

    cout << "1st Assert executed"<< endl;

    assert ((f1(10) + f2()) == 35);

    cout <<"2nd Assert executed" << endl;

    return 0;
}
