#include <assert.h>

class TEST
{
public:
    int func1()
    {
        return 56;
    }
};

int main()
{
    TEST t{};
    assert(t.func1() == 56);
    return 0;
}
