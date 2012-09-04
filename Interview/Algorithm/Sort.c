#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


/* quick sort */

int patition(int *a, int p, int r) {
  int i = p - 1, j, temp;
  int x = a[r];
  for(j = p; j < r; j++) 
    if (a[j] <= x) { i++; temp = a[i]; a[i] = a[j]; a[j] = temp; }
  temp = a[r]; a[r] = a[i+1]; a[i+1] = temp;
  return i + 1;
}

void quick_sort(int *a, int p, int r) {
  if(p < r) {
    int q = patition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
  }
}
/* end of quick sort */

/* merge sort */
void merge(int *a, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int *c = (int *)malloc((n1+1)*sizeof(int));
  int *d = (int *)malloc((n2+1)*sizeof(int));
  c[n1] = INT_MAX;
  d[n2] = INT_MAX;
  int i;
  for(i = 0; i < n1; ++i)
    c[i] = a[p+i];
  for(i = 0; i < n2; ++i)
    d[i] = a[q+1+i];
  int j, k;
  for(i = 0, j = 0, k = p; k < r + 1; ++k) {
    if(c[i] > d[j]) { a[k] = d[j]; j++; }
    else { a[k] = c[i]; i++; }
  }
  free(c);
  free(d);
}

void merge_sort(int *a, int p, int r) {
  int q = p + (r - p) / 2;
  if(p < r) {
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}
/* end of merge sort */

void insert_sort(int *a, int n) {
  int i, j;
  for(i = 1; i < n; ++i) {
    int key = a[i];
    j = i - 1;
    while(a[j] > key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key; 
  }
}

void bubble_sort(int *a, int n) {
  int i, j;
  for(i = 0; i < n - 1; ++i)
    for(j = 0; j < n - i - 1; ++j)
      if(a[j] > a[j+1]) {int tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;}
}

int main(void)
{
  int a[5] = {5, 4, 3, 2, 1};
  //bubble_sort(a, 5);
  //insert_sort(a, 5);
  quick_sort(a, 0, 4);
  int i;
  for(i = 0; i < 5; ++i) {
    printf("%d\n", a[i]);
  }
  return 0;
}
