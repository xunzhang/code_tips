#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::cout;
using std::endl;

class gen {
public:
  gen(double x_zero, double increment) : x(x_zero), incr(increment) {}
  double operator() () { x += incr; return x * x; }
private:
  double x, incr;
};

double integrate(gen g, int n) {
  vector<double> fx(n);
  std::generate(fx.begin(), fx.end(), g);
  return std::accumulate(fx.begin(), fx.end(), 0.0) / n;
}

int main(int argc, char *argv[])
{
  const int n = 10000;
  gen g(0.0, 1.0 / n);
  cout << integrate(g, n) << endl;
  return 0;
}
