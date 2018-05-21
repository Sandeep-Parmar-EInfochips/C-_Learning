#include <assert.h>
#include <vector>
#include <memory>

class TEST
{
public:
  TEST (std::unique_ptr < int > v):val (std::move (v))
  {
  }
  int func1()
  {
    return *val;
  }

private:
  std::unique_ptr < int > val;
};

int
main ()
{
  std::vector < TEST > fs;
  {
    for (int j = 0; j < 100; j++)
    {
      std::unique_ptr < int > i (new int (42));
      fs.emplace_back(std::move(i));
    }
  }

  for (auto f = fs.begin (); f != fs.end (); ++f)
  {
      assert (f->func1() == 42);
  }
}
