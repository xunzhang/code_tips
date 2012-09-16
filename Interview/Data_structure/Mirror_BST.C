/* Mirror_BST.C */
#include <iostream>
#include <stack>

typedef struct node* links;
 
struct node {
  int key;
  struct node* l;
  struct node* r;
};

void Mirror_Rec(links* root) {
  if(!*root) 
    return;
  links p = (*root)->l;
  (*root)->l = (*root)->r;
  (*root)->r = p;
  if((*root)->l) 
    return Mirror_Rec(&((*root)->l));
  if((*root)->r) 
    return Mirror_Rec(&((*root)->r));
}

void Mirror_Loop(links* root) {
  if (!*root) 
    return;  
  
  std::stack<links> stk_node;
  stk_node.push(*root);
  
  while(stk_node.size()) {
    links p = stk_node.top();
    stk_node.pop();

    links q = (*root)->l;
    (*root)->l = (*root)->r;
    (*root)->r = q;

    if(p->l) stk_node.push(p->l);
    if(p->r) stk_node.push(p->r);
  }
}
