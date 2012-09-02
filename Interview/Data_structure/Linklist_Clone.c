/* Linklist_Clone.c */
#include <stdlib.h>
typedef struct node* link;

struct node {
  int val;
  struct node* next;
  struct node* sibling;
};

void CloneNodes(link head) {
  link p = head;
  while(p) {
    link q = (link)malloc(sizeof(*q));
    q->val = p->val;
    q->next = p->next;
    q->sibling = NULL;
    
    p->next = q;
    p = q->next;
  }
}

void ConnectSiblingNodes(link head) {
  link p = head;
  while(p) {
    link q = p->next;
    if(p->sibling) {
      q->sibling = p->sibling->next;
    }
    p = q->next; 
  }
}

link ReconnectNodes(link head) {
  link p = head;
  link q_head = NULL;
  link q = NULL;
  
  if(p) {
    q_head = q = p->next;
    p->next = q->next;
    p = p->next;
  }
  
  while(p) {
    q->next = p->next;
    q = q->next;

    p->next = q->next;
    p = p->next; 
  }
  
  return q_head;
}

link Clone(link head) {
  CloneNodes(head);
  ConnectSiblingNodes(head);
  return ReconnectNodes(head);
}
