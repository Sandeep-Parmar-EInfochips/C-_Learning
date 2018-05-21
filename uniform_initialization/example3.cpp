#include <assert.h>
#include <initializer_list>
#include <stdexcept>
#include <cstdint>
#include <vector>

class relay_bank
{
public:
    relay_bank(size_t s) : size(s), bank((s+7)/8)
    {
    }

    relay_bank(std::initializer_list<uint8_t> l) : bank(l), size(l.size())
    {
    }

    bool operator[](size_t i)
    {
        if(i > size)
        {
            throw std::out_of_range("index: " + std::to_string(i) + ", size: " + std::to_string(size));
        }
        return bank[i];
    }

private:
    std::vector<uint8_t> bank;
    size_t size;
};

int main()
{
    relay_bank b = {true, false, true, true, true, false, true, false, false, true,
                    true, false, false, false, false, true, true, true, false, true,
                    false, true, true, true, false, false, true, false, true, true};

    assert(b[10] == true);
    assert(b[20] == false);
    return 0;
}
