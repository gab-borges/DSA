#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class Node {
public:
    char info;
    int height;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    /* Methods */
    Node(char value) : info(value), height(1), left(nullptr), right(nullptr) {}
    
    void print() const; // In-Order Print
};

class Tree {
private:
    unique_ptr<Node> root;

    int getHeight(const unique_ptr<Node>& node) const; //WTF

    /* Rotations */
    unique_ptr<Node> simple_left(unique_ptr<Node> node);
    unique_ptr<Node> simple_right(unique_ptr<Node> node);
    unique_ptr<Node> double_left(unique_ptr<Node> node);
    unique_ptr<Node> double_right(unique_ptr<Node> node);

    /* Update the Balance Factor and Height */
    unique_ptr<Node> update_bf_left(unique_ptr<Node> node);
    unique_ptr<Node> update_bf_right(unique_ptr<Node> node);
    void update_height(Node& node); //WTF

public:
    void insert (char value);
    void remove (char value);
    int balance(const unique_ptr<Node>& node) const; //WTF
};

#endif