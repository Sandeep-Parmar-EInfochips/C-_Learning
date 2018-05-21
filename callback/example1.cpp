#include <iostream>
#include <string>
using std::string;
using namespace std;

//Interface Class

class CallbackInterface
{
public:
    // The prefix "cbi" is to prevent naming clashes.
    virtual int cbiCallbackFunction(int) = 0;
};

class Callee : public CallbackInterface
{
public:
    // The callback function that Caller will call.
    int cbiCallbackFunction(int i)
    {
        cout << "Callee::cbiCallbackFunction() inside callback" << endl;
        return 2 * i;
    }
};

class Caller
{
public:
    // Clients can connect their callback with this
    void connectCallback(CallbackInterface *cb)
    {
        m_cb = cb;
    }
    // Test the callback to make sure it works.
    void test()
    {
        cout << "Caller::test() calling callback..." << endl;
        int i = m_cb -> cbiCallbackFunction(10);
        cout << "Result (20):" << i << endl;
    }
private:
    // The callback provided by the client via connectCallback().
    CallbackInterface *m_cb;
};

int main()
{
    Caller caller;
    Callee callee;
    // Connect the callback
    caller.connectCallback(&callee);
    // Test the callback
    caller.test();

    return 0;
}
