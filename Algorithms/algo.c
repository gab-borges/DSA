#include "algo.h"

/* */
void bubble_sort (int *A, int n) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j] > A[j + 1])
				swap (A, j, j + 1);
}

void selection_sort (int *A, int n) {
  int i, j, min;

  for (i = 0; i < n; i++) {
    min = i;

    for (j = i + 1; j < n; j++)
      if (A[j] < A[min])
        min = j;

    swap (A, i, min);
  }
}

void insertion_sort (int *A, int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = A[i];

    for (j = i - 1; j >= 0 && A[j] > key; j--)
      A[j + 1] = A[j];

    A[j + 1] = key;
  }
}


/* */
void swap (int *A, int i, int j) {
	int aux = A[i];
	A[i] = A[j];
	A[j] = aux;
}

void print (int *A, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int check (int *A, int n, int ascending) {
  int i;
  for (i = 1; i < n; i++) {
    if (ascending) {
      if (A[i-1] > A[i])
        return FALSE;	      
    }
    else {
      if (A[i-1] < A[i])
        return FALSE;	      
    }    
  }
  return TRUE;  
}