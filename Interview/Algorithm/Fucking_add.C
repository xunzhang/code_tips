/* Fucking_add.C */
#include <iostream>

class add {
public:
  add() { ++n; sum += n; }
  static int getsum() { return sum; }
private:
  static int n;
  static int sum;
};

int add::n = 0;
int add::sum = 0;

int main()
{
  //add* obj = new add[100];
  //delete [] obj;
  add obj[100];
  std::cout << add::getsum() << std::endl;
}
