#include "sorting.h"

int main() {
  int n;

  printf("\t\tBubble\t\tSelection\tInsertion\n");

  for (n = 10; n <= 10000; n*=10) {
  	int *A = (int*) malloc (n * sizeof(int));
    int *B = (int*) malloc (n * sizeof(int));
    int *C = (int*) malloc (n * sizeof(int));

    int i;
    for (i = 0; i < n; i++) {
      A[i] = rand() % (n + 1);
      B[i] = A[i];
      C[i] = A[i];
    }

    printf("%d\t\t", n);

    clock_t start, end;
    double elapsed_time;

    start = clock();
    bubble_sort (A, n);
    end = clock();
    elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    printf("%.2f\t\t", elapsed_time);

    start = clock();
    selection_sort (B, n);
    end = clock();
    elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    printf("%.2f\t\t", elapsed_time);
    
    start = clock();
    insertion_sort (C, n);
    end = clock();
    elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    printf("%.2f\n", elapsed_time);
  }
  
  return 0;
}