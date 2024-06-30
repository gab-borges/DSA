#ifndef _singly_linked_list_h_
#define _singly_linked_list_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Singly Linked List
typedef struct node {
  int data;
  struct node *next;
} List;


/* * Functions * */

/* Creates a singly linked list.*/
List* create ();

/* Prints a linked list. O(n)*/
void print (List *l);

/* Frees the memory of a linked list. O(n)*/
void destroy (List *l);

/* Inserts a new element at the front of a linked list. O(1)*/
List* insert_front (List *l, int val);

/* Inserts a new element at the end of a linked list. O(n)*/
List* insert_back (List *l, int val);

/* Removes the first element with value 'val'. O(n)*/
List* remove_value (List *l, int val);

/* Removes the element at k-th position. O(k)*/
List* remove_k (List *l, int k);

/* Searches a value in a linked list. O(n)*/
List* search (List *l, int val);

#endif