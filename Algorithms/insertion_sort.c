#include <stdio.h>
#include <stdlib.h>

void insertion_sort (int *A, int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = A[i];

    for (j = i - 1; j >= 0 && A[j] > key; j--)
      A[j + 1] = A[j];

    A[j + 1] = key;
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
  insertion_sort (A, n);
  print (A, n);  
  
  return 0;
}
