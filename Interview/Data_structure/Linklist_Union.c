/* Linklist_Union.c */
#include <stdlib.h>
typedef struct node* link;

struct node {
  int val;
  struct node* next;
};

void Union(link *h1, link *h2, link result) {
  
  link p1, p2;

  if (!(*h1) && !(*h2)) 
    exit(1);
  else if(!(*h1)) { result = *h2; return; }
  else if(!(*h2)) { result = *h1; return; }

  p1 = (*h1)->val > (*h2)->val ? *h2 : *h1;
  p2 = (*h1)->val > (*h2)->val ? *h1 : *h2;
  result = p1;
  
  while(!p1 && !p2) {
    int s;
    link tmp1, tmp2;
    if(p1->val < p2->val) 
      p1 = p1->next;
    else {
      tmp1 = p1; tmp2 = p2;
      p1 = p1->next; p2 = p2->next;
      tmp1->next = tmp2;
      tmp2->next = p1;
      s = tmp1->val; tmp1->val = tmp2->val; tmp2->val = s;
    }
  } 
}

