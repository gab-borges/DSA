#include <stdio.h>
#include <stdlib.h>

void merge (int *A, int left, int middle, int right, int *O) {
  int i = left;
  int j = middle + 1;
  int k = left;

  while (i <= middle && j <= right) {
    if (A[i] <= A[j])
      O[k++] = A[i++];

    else
      O[k++] = A[j++];
  }

  while (i <= middle)
    O[k++] = A[i++];
 
  while (j <= right)
    O[k++] = A[j++];
  
  for (i = left; i <= right; i++)
    A[i] = O[i];
}

void merge_sort (int *A, int left, int right, int *O) {
  if (left < right) {
    int middle = (left + right) / 2.0;

    merge_sort (A, left, middle, O);
    merge_sort (A, middle + 1, right, O);

    merge (A, left, middle, right, O);
  }
}

void print (int A[], int n) {
  int i;

  for (i = 0; i < n; i++)
    printf("%d ", A[i]);

  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  int *A = (int*) malloc (n * sizeof(int));
  int *O = (int*) malloc (n * sizeof(int));
  
  int i;
  for(i=0; i<n; i++)
    A[i] = (rand() % n) + 1;

  print (A, n);
  merge_sort (A, 0, n - 1, O);
  print (A, n);  
  
  return 0;
}
