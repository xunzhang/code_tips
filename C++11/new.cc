#include <iostream>

int foo(const int & v) {
  return v;
}
// #define a 10
// #define default_foo foo
// const, constexpr

const int a = 10;
constexpr auto default_foo = foo;

enum class WierdLogic : unsigned {
  NO,
  MAYBE = 5,
  YES = 10
};
enum class Color{RED, GREEN, BLUE}; 
enum class Stoplight{RED, YELLOW, GREEN};
std::ostream& operator << (std::ostream& os, const WierdLogic & obj) {
  os << static_cast<std::underlying_type<WierdLogic>::type>(obj);
  return os;
}

int main(int argc, char *argv[])
{
  { // enum
    auto yes = WierdLogic::YES;
    auto c_red = Color::RED;
    auto s_red = Stoplight::RED;
    std::cout << yes << std::endl;
  }
  return 0;
}
