#include <vector>
#include <inttypes.h>

class Test
{
public:
  Test() : bytes(1024, 42)
  {
  }

private:
  std::vector<uint8_t> bytes;
};


int main()
{
  Test f;
  for(unsigned int i = 0; i < 1024 * 1024; ++i)
  {
    Test g = std::move(f);
  }
}
