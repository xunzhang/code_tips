/* Find_Path.C */
#include <iostream>
#include <vector>

typedef struct node* links;

struct node {
  int val;
  struct node* l;
  struct node* r;
};

void find_path(links root, int sum, std::vector<int>& path, int& curr) {
  if(!root) return;
  curr += root->val;
  path.push_back(root->val);

  bool is_leaf = (!root->l && !root->r);

  if(curr == sum && is_leaf) {
    std::vector<int>::iterator iter = path.begin();
    for(; iter != path.end(); ++iter)
      std::cout << *iter << " ";
    std::cout << std::endl;
  }
  
  if(curr < sum) {
    if(root->l)
      find_path(root->l, sum, path, curr);
    if(root->r)
      find_path(root->r, sum, path, curr);
  }
  
  curr -= root->val;
  path.pop_back();
  
}
