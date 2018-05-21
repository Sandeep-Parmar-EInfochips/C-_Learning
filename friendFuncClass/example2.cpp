#include <iostream>
class A {
private:
    int a;
public:
    int bb = 10;
    A() { a=0; }
    friend class B;     // Friend Class
};

class B {
private:
    int b;
public:
    void showA(A& x) {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a=" << x.a<< std::endl;
    }

    int returnA(A& x) {
        // Since B is friend of A, it can access
        // private members of A
        return x.a;
    }
};

int main() {
    A aq;
    std::cout << "value of public veriable is : " << aq.bb << std::endl;
    B b;
    b.showA(aq);
    std::cout << "return value is : " << b.returnA(aq) << std::endl;
    return 0;
}
