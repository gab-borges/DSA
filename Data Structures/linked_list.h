#ifndef _list_h_
#define _list_h_

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

/* */
List* create ();
void print (List *l);
void destroy (List *l);
List* insert_front (List *l, int val);
List* insert_back (List *l, int val);
List* remove_value (List *l, int val);
List* remove_k (List *l, int k);
List* search (List *l, int val);

#endif