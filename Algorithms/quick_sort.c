#include <stdio.h>
#include <stdlib.h>

void swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int partition (int *A, int left, int right) {
  int pivot = A[right];

  int j, i = left - 1;
  for (j = left; j < right; j++)
    if (A[j] <= pivot)
      swap (A, ++i, j);

  swap (A, ++i, right);
  return (i);
}

void quick_sort (int *A, int left, int right) {
  if (left < right) {
    int pivot = partition (A, left, right);

    quick_sort (A, left, pivot - 1);
    quick_sort (A, pivot + 1, right);
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

  int i;
  for(i=0; i<n; i++)
    A[i] = (rand() % n) + 1;

  print (A, n);
  quick_sort (A, 0, n - 1);
  print (A, n);  
  
  return 0;
}
