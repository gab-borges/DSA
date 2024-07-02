#ifndef _sorting_h_
#define _sorting_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/* Utility Functions */

// Swaps two elements in an array | O(1)
void swap (int *A, int i, int j);

// Prints the elements of an array | O(n)
void print (int *A, int n);

// Checks if an array is sorted | O(n)
int check (int *A, int n, int ascending);


/* Sorting Functions */
void bubble_sort (int *A, int n);
void selection_sort (int *A, int n);
void insertion_sort (int *A, int n);
void quick_sort (int *A, int left, int right);

//void merge_sort (int *A, int left, int right, int *O);

#endif