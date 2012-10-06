#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
    
void three_Sum(vector<int> &num, vector< vector<int> >& result) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int j, k, sum;
        vector<int> temp;
        std::sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; ++i) {
            if(i >= 1 && num[i] == num[i-1]) continue;
            j = i + 1;
            k = num.size() - 1;
            while(j < k) {
                sum = num[i] + num[j] + num[k];
                if(sum == 0) {
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(num[k]);
                    result.push_back(temp);
                    temp.resize(0);
                    j++;
                    k--;
                }
                else if(sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
}

int main()
{
  vector<int> a;
  a.push_back(-1);
  a.push_back(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(-1);
  a.push_back(-4);
  vector< vector<int> > res;
  three_Sum(a, res);
  std::cout << res[0][0] << std::endl;
  std::cout << res[0][1] << std::endl;
  std::cout << res[0][2] << std::endl;
  std::cout << res[1][0] << std::endl;
  std::cout << res[1][1] << std::endl;
  std::cout << res[1][2] << std::endl;
}
