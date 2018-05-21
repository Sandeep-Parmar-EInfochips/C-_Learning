#include <functional>
#include <assert.h>

using namespace std::placeholders;

int func1(int i)
{
    return i;
}

int func2()
{
    return 42;
}

int main()
{


    std::function<int (int)> f = std::bind(func1, _1);
    std::function<int ()> g = std::bind(func2);

    assert( (f(10) + g()) == 52);
    return 0;
}
