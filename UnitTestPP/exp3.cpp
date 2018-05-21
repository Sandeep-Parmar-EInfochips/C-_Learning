#include "UnitTest++/UnitTest++.h"

#include "TestReporterStdout.h"

#define SUITE_NAME "BowlingGameTest2"

using namespace UnitTest;

class Game
{
public:
    Game()
        : total_(0)
    {
    }

    void roll(int pins)
    {
        total_ += pins;
    }

    int score() const
    {
        return total_;
    }

private:
    int total_;
};

SUITE(BowlingGameTest)
{
    TEST(GutterGame)
    {
        Game g;

        for (int i = 0; i < 20; ++i)
        {
            g.roll(0);
        }

        CHECK_EQUAL(0, g.score());
    }

    TEST(AllOnes)
    {
        Game g;

        for (int i = 0; i < 20; ++i)
        {
            g.roll(1);
        }

        CHECK_EQUAL(20, g.score());
    }
}

SUITE(BowlingGameTest2)
{
    class GameFixture
    {
    public:
        Game g;
    };

    TEST_FIXTURE(GameFixture, GutterGame)
    {
        for (int i = 0; i < 20; ++i)
        {
            g.roll(0);
        }

        CHECK_EQUAL(0, g.score());
    }

    TEST_FIXTURE(GameFixture, AllOnes)
    {
        for (int i = 0; i < 20; ++i)
        {
            g.roll(1);
        }

        CHECK_EQUAL(20, g.score());
    }
}

SUITE(BowlingGameTest3)
{
    class GameFixture
    {
    public:
        Game g;

        void rollMany(int rolls, int pinsPerRoll)
        {
            for (int i = 0; i < rolls; ++i)
            {
                g.roll(pinsPerRoll);
            }
        }
    };

    TEST_FIXTURE(GameFixture, GutterGame)
    {
        rollMany(20, 0);
        CHECK_EQUAL(0, g.score());
    }

    TEST_FIXTURE(GameFixture, AllOnes)
    {
        rollMany(20, 1);
        CHECK_EQUAL(20, g.score());
    }
}


int main(int, const char *[])
{
#ifdef SUITE_NAME
    TestReporterStdout reporter;
    TestRunner runner( reporter );
    return runner.RunTestsIf( Test::GetTestList() ,  SUITE_NAME , True(), 0 );
#else
    return RunAllTests();
#endif
    //return UnitTest::RunAllTests();
}
