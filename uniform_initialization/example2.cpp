#include <assert.h>
#include <algorithm>
#include <vector>

int fib()
{
    static int fnn = 1;
    static int fn = 0;

    int fnnn = fn + fnn;
    int f = fn;
    fn = fnn;
    fnn = fnnn;
    return f;
}

std::vector<int> v = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};

int main()
{
    std::vector<int> expected(47);
    std::generate(expected.begin(), expected.end(), fib);
    assert(v == expected);
    return 0;
}