#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

/* Template class of a node */
template <typename T> class Node {
public:
    T info;
    Node* left;
    Node* right;
    int height;

    /* Constructor that receives a value */
    Node(T value)
        : info(value)
        , left(nullptr)
        , right(nullptr)
        , height(1)
    {
    }
};

/* Template class of an AVL Tree */
template <typename T> class Tree {
public:
    Node<T>* root;

    int height (Node<T>* node);
    int balanceFactor (Node<T>* node);
    void update_height (Node<T>* node);

    /* Rotations */
    Node<T>* simple_left (Node<T>* node);
    Node<T>* simple_right (Node<T>* node);
    Node<T>* double_left (Node<T>* node);
    Node<T>* double_right (Node<T>* node);

    /* Update the Balance Factor and Height */
    Node<T>* update_bf_left (Node<T>* node);
    Node<T>* update_bf_right (Node<T>* node);

    Node<T>* insertNode (Node<T>* node, T value);
    Node<T>* removeNode (Node<T>* node, T target);

    bool searchNode (Node<T>* node, T value);

    /* In-Order traversal */
    void inOrder(Node<T>* node);

public:
    Tree()
        : root(nullptr)
    {
    }

    /* __ Interface __ */
    /* Inserts a value into the tree */
    void insert (T value);
    
    /* Removes a value from the tree */
    void remove (T target);

    /* Searches for a value in the tree */
    bool search (T value);
    
    /* Prints the In-Order traversal of the tree */
    void print();
};

#endif
