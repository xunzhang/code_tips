/* Verify_Squ_Bst.C */
#include <iostream>

bool VerifySquenceOfBST(int* seq, int length) {
  if(seq == NULL || length <= 0) return false;
  int root = seq[length - 1];
  
  int i = 0;
  for(; i < length - 1; ++i)
    if(seq[i] > root) break;
  
  int j = i;
  for(; j < length - 1; ++j)
    if(seq[j] < root) return false;

  bool left = true;
  if(i > 0) left = VerifySquenceOfBST(seq, i);
  bool right = true;
  if(i < length - 1) right = VerifySquenceOfBST(seq + i, length - i - 1);
  
  return (right && right);
}

int main()
{
  int a[4] = {7, 4, 6, 5};
  std::cout << VerifySquenceOfBST(a, 4) << std::endl;
  int b[] = {5, 7, 6, 9, 11, 10, 8};
  std::cout << VerifySquenceOfBST(b, 7) << std::endl;
}
