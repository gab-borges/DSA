#ifndef _doubly_linked_list_h_
#define _doubly_linked_list_h_

/* Doubly Linked List */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

// Doubly Linked List
typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} List;

/* * Functions * */
List* create();
void print(List *l);
void destroy(List *l);


#endif