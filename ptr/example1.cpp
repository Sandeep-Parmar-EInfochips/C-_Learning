#include <assert.h>
#include <memory>
////////////////////////////////////////////////////////////////////////////////
//
// Assignment: compile existing program and run using valgrind, and save the
// output.  Next, modify the program so that it uses managed pointers instead of
// raw pointers.  Run the modified program using valgrind, and compare outputs.
// Run the program using a debugger, and step through copying and deleting the
// managed pointers.
//
////////////////////////////////////////////////////////////////////////////////
class TEST
{
public:
    TEST(std::unique_ptr<int> v) : val(std::move(v)) {}
    int func1()
    {
        return *val;
    }
private:
    std::unique_ptr<int> val;
};

int main()
{
    std::unique_ptr<int> i(new int(42));
    TEST t(std::move(i));
    assert(t.func1() == 42);
}
