/* heap_sort.c */

#include <stdio.h>

#define LEFT(a) ((2 * a) + 1)
#define RIGHT(a) (2 * (a + 1))

int heap_size = 0;

void max_heapify(int *a, int i) {
  int l, r;
  int largest;
  l = LEFT(i);
  r = RIGHT(i);
  
  if(l <= heap_size && a[i] < a[l]) 
    largest = l;
  else
    largest = i;
  if(r <= heap_size && a[largest] < a[r])
    largest = r;
  if(largest != i) {
    int tmp; tmp = a[i]; a[i] = a[largest]; a[largest] = tmp;
    max_heapify(a, largest);
  }
}

/* loop version
void max_heapify_loop(int *a, int i) {
  int l, r;
  int largest;
  l = LEFT(i);
  r = RIGHT(i);

  while(l < heap_size) {
    if(a[i] < a[l]) largest = l;
    else largest = i;
    if(r < heap_size && a[largest] < a[r])
      largest = r;
    if(largest != i) {
      int tmp; tmp = a[i]; a[i] = a[largest]; a[largest] = tmp;
      i = largest;
      l = LEFT(i);
      r = RIGHT(i);
    }
    else break;
  }
}
*/

void build_max_heap(int *a, int size) {
  heap_size = size;
  int i = (size - 1) / 2;
  while(i >= 0) {
    max_heapify(a, i);
    i --;
  }
}

void heap_sort(int *a, int size) {
  build_max_heap(a, size);
  int i;
  for(i = size; i > 0; --i) {
    int tmp; tmp = a[i]; a[i] = a[0]; a[0] = tmp;
    heap_size --;
    max_heapify(a, 0);
  }
}

int main(void)
{
  int a[5] = {3, 1, 5, 2, 4};
  heap_sort(a, 4);
  int i;
  for(i = 0; i < 5; ++i)
    printf("%d\n", a[i]);
  return 0;
}
