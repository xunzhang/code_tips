/* Sub_Tree.C */
#include <iostream>

typedef struct node* links;

struct node {
  int val;
  struct node* l;
  struct node* r;
};

bool Sub_Tree(links, links);
bool Tree_all_Nodes(links, links);

bool Sub_Tree(links p1, links p2) {

  if((p1 == NULL && p2 != NULL) || (p1 != NULL && p2 == NULL)) return false;
  if(p1 == NULL && p2 == NULL) return true; 

  bool result = false;
  
  if(p1->val == p2->val)  result = Tree_all_Nodes(p1, p2);
  if(!result && p1->l != NULL)
    result = Sub_Tree(p1->l, p2);
  if(!result && p1->r != NULL)
    result = Sub_Tree(p1->r, p2);
  
  return result;
}

bool Tree_all_Nodes(links p1, links p2) {
  if(!p2) return true;
  if(!p1) return false;
  if(p1->val != p2->val) return false;
  
  return Tree_all_Nodes(p1->l, p2->l) && Tree_all_Nodes(p1->r, p2->r);
}
