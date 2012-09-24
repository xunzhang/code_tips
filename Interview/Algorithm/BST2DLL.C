/* BST2DLL.C */
void Convert_Node(links pNode, links& plast) {
  if(!pNode) return NULL;
  links curr = pNode;
  if(pNode->l) Convert_Node(curr->l, plast);
  curr->l = plast;
  if(plast) plast->r = curr;
  plast = curr;
  if(pNode->r) Convert_Node(curr->r, plast);
}

links Convert_solution(links root) {
  links tmp = NULL;
  while(Convert_Node(root, tmp)) tmp = tmp->l;
  return tmp;
}
