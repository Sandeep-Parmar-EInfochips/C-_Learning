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

    int func2(const Test &_test)
    {
        return _test.x + x;
    }

    float func3(float _f)
    {
        //cout<<"func3 value : " << _f << endl;
        return _f;
    }


private:
    int x;
};


int main()
{
    Test t1(25);
    Test t2(10);

    function< int (int)> f1 = bind(&Test::func1,t1,_1);
    function <int ()> f2 = bind(&Test::func2,ref(t1),cref(t2));
    function< int (float , int)> f3 = bind(&Test::func1,t1,_2);

    assert((f1(10) + f2()) == 45 );

    cout << "1st Assert executed"<< endl;

    assert ((f3(10.011,10) + f2()) == 45);
    cout <<"2nd Assert executed" << endl;

    return 0;
}
