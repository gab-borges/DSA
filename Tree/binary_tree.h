#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Binary Tree
typedef struct tree {
    char info;
    struct tree *left;
    struct tree *right;
} Tree;

// Creates an empty tree
Tree* create_empty_tree (void);

// Builds a binary tree
Tree* build_tree (char c, Tree *l, Tree *r);

// Verifies whether the given tree is empty
int is_empty (Tree *a);

// Frees the memory of a binary tree
void free_tree (Tree *a);

#endif