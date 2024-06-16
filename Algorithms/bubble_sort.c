#include <stdio.h>
#include <stdlib.h>

void swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

void bubble_sort (int *A, int n) {
  int i, j;
  
  for (i = 0; i < n; i++)
    for (j = 0; j < n - 1 - i; j++)
      if (A[j] > A[j+1])
        swap (A, j, j + 1);
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
  bubble_sort (A, n);
  print (A, n);  
  
  return 0;
}
