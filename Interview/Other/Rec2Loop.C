/* Rec2Loop.C */
#include <stack>

// rec version of mirror
void mirror(links root) {
  if(!root) return;
  links tmp = root->l; root->l = root->r; root->r = tmp;
  if(root->l) mirror(root->l);
  if(root->r) mirror(root->r);
}

// loop version of mirror
void mirror(links root) {
  if(!root) return;
  std::stack<links> stk;
  stk.push(root);
  while(stk.size()) {
    links root_bak = stk.top();
    stk.pop();
    links tmp = root_bak->l; root_bak->l = root_bak->r; root_bak->r = tmp;
    if(root->l) stk.push(root_bak->l);
    if(root->r) stk.push(root_bak->r);
  }
}

// rec version of func
void func(const Node& node) {
  if(ShouldReturn(node)) return;
  for(int i = 0; i < node.children_size(); ++i) {
    const Node& child_node = node.child(i);
    func(child_node);
    DoSomethingA();
  }
  DoSomethingB();
}

// loop version of func
void func(const Node& node) {
  if(ShouldReturn(node)) return;
  std::stack<Node> stk;
  std::stack<int> stk_owe;
  stk.push(node);
  while(stk.size()) {
    const Node& temp_node = stk.top();
    stk.pop();
    count ++; // owe number of B
    for(int i = 0; i < temp_node.children_size(); ++i) {
      const Node& child_node = temp_node.child(i);
      stk.push(child_node);
      DoSomethingA();
    }
    DoSomethingB();
  }
}
