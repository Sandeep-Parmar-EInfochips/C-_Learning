#include "UnitTest++/UnitTest++.h"


class MyFixture
{
public:
   MyFixture() { /* setup goes here */ }
   ~MyFixture() { /* teardown goes here */ }

public:
   int ADD(int a, int b)
   {
       return a+b;
   }

   int MUL(int a, int b)
   {
       return a*b;
   }
};

//TEST_FIXTURE(MyFixture, MyFixtureTest)
//{
//   // checks go here
//    MyFixture f;
//    int a = 1, b = 2;
//    CHECK_EQUAL((a+b),f.ADD(a,b));

//    CHECK_EQUAL((a*b),f.MUL(a,b));
//}

TEST(Add)
{
    MyFixture f;
    int a = 1, b = 2;
    CHECK_EQUAL((a+b),f.ADD(a,b));
}

TEST(Mul)
{
    MyFixture f;
    int a = 1, b = 2;
    CHECK_EQUAL((a*b),f.MUL(a,b));
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
