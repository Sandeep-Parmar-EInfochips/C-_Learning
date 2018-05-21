#include <assert.h>
#include <vector>
#include <functional>
#include <memory>

class TEST
{
public:
    TEST(std::unique_ptr<int> v) : val(std::move(v)) {}
    std::function<int ()> get_func1()
    {
        return std::bind(&TEST::funct1, this);
    }
    int funct1()
    {
        return *val;
    }
private:
    std::unique_ptr<int> val;
};

int main()
{
    std::unique_ptr<int> i(new int(42));
    std::unique_ptr<TEST> t1(new TEST(std::move(i)));
    std::function<int ()> f = t1->get_func1();
    assert(f() == 42);
}
