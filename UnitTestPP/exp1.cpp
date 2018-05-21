#include "UnitTest++/UnitTest++.h"

TEST(Sanity)
{
   CHECK_EQUAL(1, 1);
}

TEST(Sanity1)
{
   CHECK_EQUAL(2, 1);
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
