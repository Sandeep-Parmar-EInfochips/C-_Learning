#include <iostream>
#include <string>
#include <stdio.h>
#include <memory>
using std::string;
using namespace std;

//C++11 Lambda Functions

class Callee
{
public:
    Callee(int i) : m_i(i) { }
    // The callback function that Caller will call.
    int callbackFunction(int i)
    {
        cout << " Callee::callbackFunction() inside callback" << endl;
        return m_i * i;
    }
private:
    // To prove "this" is indeed valid within callbackFunction().
    int m_i;
};


typedef function<int(int)> CallbackFunction;
class Caller
{
public:
    // Clients can connect their callback with this.
    void connectCallback(CallbackFunction cb)
    {
        m_cb = cb;
    }
    // Test the callback to make sure it works.
    void test()
    {
        cout << "Caller::test() calling callback..."<< endl;
        int i = m_cb(10);
        cout << "Result (50): " << i << endl;
    }
private:
    // The callback provided by the client via connectCallback().
    CallbackFunction m_cb;
};




int main()
{

    Caller caller;
    Callee callee(5);
    // Connect the callback. Like with the C-style function pointer and
    // static function, we use a lambda to get back into the object.
    caller.connectCallback([&callee](int i) { return callee.callbackFunction(i); });
    // Test the callback
    caller.test();

    return 0;
}
