#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Árvore
typedef struct tree {
    char info;
    struct tree *left;
    struct tree *right;
} Tree;

Tree* create_empty_tree (void);
Tree* build_tree (char c, Tree *l, Tree *r);
int is_empty (Tree *a);
void free_tree (Tree *a);

#endif