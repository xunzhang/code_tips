/* Traverse_Binary_Tree.C */
#include <stack>
#include <iostream>

typedef struct node* l_node;

struct node {
  char key;
  struct node* l;
  struct node* r;
};

void pre_order_rec(l_node root, void (*visit)(l_node)) {
  if(!root) return;
  visit(root);
  pre_order_rec(root->l, visit);
  pre_order_rec(root->r, visit);
}

void pre_order_loop_v1(l_node root, void (*visit)(l_node)) {
  std::stack<node> stk;
  stk.push(root);
  while(!stk.empty()) {
    l_node fnode = stk.top();
    visit(fnode);
    stk.pop();
    if(root->l) stk.push(root->l);
    if(root->r) stk.push(root->r);
  }
}

void pre_order_loop_v2(l_node root, void (*visit)(l_node)) {
  std::stack<node> stk;
  while(root != NULL || !stk.empty()) {
    if(root != NULL) {
      visit(root);
      stk.push(root);
      root = root->left;
    } else {
      root = stk.top();
      stk.pop();
      root = root->right;
    }
  }
}

void in_order_rec(l_node root, void (*visit)(l_node)) {
  if(!root) return;
  in_order_rec(root->l, visit);
  visit(root);
  in_order_rec(root->r, visit);
}

void in_order_loop(l_node root, void (*visit)(l_node)) {
  std::stack<node> stk;
  while(root != NULL || !stk.empty()) {
    if(root != NULL) {
      stk.push(root);
      root = root->left;
    }else {
      root = stk.top();
      visit(root);
      stk.pop();
      root = root->right;
    }
  }
}

void post_order_rec(l_node root, void (*visit)(l_node)) {
  if(!root) return;
  post_order_rec(root->l, visit);
  post_order_rec(root->r, visit);
  visit(root);
}

void post_order_rec(l_node root, void (*visit)(l_node)) {
  std::stack<node> stk;
  std::stack<node> stk2;
  stk.push(root);
  while(!stk.empty()) {
    l_node fnode = stk.top();
    stk2.push(fnode);
    stk.pop();
    if(fnode->l) stk.push();
    if(fnode->r) stk.push();
  }
  while(!stk2.empty()) {
    visit(stk2.top());
    stk2.pop();
  }
}

void dfs(l_node root, void (*visit)(l_node)) {
  pre_order(root, visit);
}

static int depth(l_node root) {
  if(!root) return 0;
  int l = depth(root->l);
  int r = depth(root->r)'
  return (1 + l > r ? l : r);
}

static void print_level(l_node root, void (*visit)(l_node), int level) {
  if(level == 1)
    visit(l_node->key);
  else {
    print_level(l_node->l, visit, level - 1);
    print_level(l_node->r, visit, level - 1);
  }
}

void level_order_rec(l_node root, void (*visit)(l_node)) {
  int dep = depth(root);
  for(int i = 1; i < dep + 1; ++i) {
    print_level(root, visit, i);
    std::cout << std::endl;
  }
}


