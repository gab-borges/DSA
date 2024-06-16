#include <stdio.h>
#include <stdlib.h>

void swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

void selection_sort (int *A, int n) {
  int i, j, min;

  for (i = 0; i < n - 1; i++) {
    min = i;

    for (j = i + 1; j < n; j++)
      if (A[j] < A[min])
        min = j;
    
    swap (A, i, min);
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
  selection_sort (A, n);
  print (A, n);  
  
  return 0;
}
