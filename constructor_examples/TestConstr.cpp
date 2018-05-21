#include<iostream>
using namespace std;

class TestConstructor
{
private:
    int x, y;
//    int *c;
public:
    TestConstructor()
    {
        x = 0;
        y = 0;
        cout << "Default Constructor is called " <<endl;
    }

    TestConstructor(int x1, int y1)
    {
        x = x1;
        y = y1;
        cout << "Perameterized Constructor is called" <<endl;
    }

    TestConstructor(const TestConstructor &t)
    {
        x = t.x;
        y = t.y;
        cout << "Copy Constructor is called" <<endl;
    }

    TestConstructor& operator = (const TestConstructor &t)
    {
        x = t.x;
        y = t.y;
        cout<<"Assignment operator is called "<<endl;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void setX(int _x)
    {
        x = _x;
    }
    void setY(int _y)
    {
        y = _y;
    }
};

int main()
{
    TestConstructor t0; // Default constructor is called hear
    cout << "t0.x = " << t0.getX() << ", t0.y = " << t0.getY() << endl;

    TestConstructor t1(10, 15); // Normal perameterized constructor is called here
    cout << "t1.x = " << t1.getX() << ", t1.y = " << t1.getY() << endl;

    TestConstructor t2 = t1; // Copy constructor is called here
    cout << "t2.x = " << t2.getX() << ", t2.y = " << t2.getY() << endl;

    TestConstructor t3(50,60);
    cout << "t3.x = " << t3.getX() << ", t3.y = " << t3.getY() << endl;
    t3 = t1;
    cout << "t3.x = " << t3.getX() << ", t3.y = " << t3.getY() << endl;

    return 0;
}
