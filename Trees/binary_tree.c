#include "binary_tree.h"

/* */
Tree* create_empty_tree (void) {
    return NULL;
}

/* */
Tree* build_tree (char c, Tree *l, Tree *r) {
    Tree *node = (Tree*) malloc (sizeof(Tree));
    
    node->left = l;
    node->right = r;
    
    return node;
}

/* */
int is_empty (Tree *a) {
    return (a == NULL);
}

/* */
void free_tree (Tree *a) {
    if (is_empty(a))
        return;

    free_tree (a->left);

    free_tree (a->right);

    free (a);
}
