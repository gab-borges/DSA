#include "avl_tree.hpp"

template <typename T>
int Tree<T>::height(Node<T>* node) {
    return (node ? node->height : -1);
}

template <typename T>
int Tree<T>::balanceFactor(Node<T>* node) {
    return (height(node->right) - height(node->left));
}

template <typename T>
void Tree<T>::update_height(Node<T>* node) {
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

template <typename T>
Node<T>* Tree<T>::simple_left(Node<T>* node) {
    Node<T>* aux = node->right;
    node->right = aux->left;
    aux->left = node;

    return aux;
}

template <typename T>
Node<T>* Tree<T>::simple_right(Node<T>* node) {
    Node<T>* aux = node->left;
    node->left = aux->right;
    aux->right = node;

    return aux;
}

template <typename T>
Node<T>* Tree<T>::double_left(Node<T>* node) {
    node->right = simple_right(node->right);

    return simple_left(node);
}

template <typename T>
Node<T>* Tree<T>::double_right(Node<T>* node) {
    node->left = simple_left(node->left);

    return simple_right(node);
}

template <typename T>
Node<T>* Tree<T>::update_bf_left(Node<T>* node) {
    update_height(node);

    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) <= 0)
            node = simple_right(node);

        else
            node = double_right(node);
    }

    return node;
}

template <typename T>
Node<T>* Tree<T>::update_bf_right(Node<T>* node) {
    update_height(node);

    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) >= 0)
            node = simple_left(node);

        else
            node = double_left(node);
    }

    return node;
}

template <typename T>
Node<T>* Tree<T>::insertNode(Node<T>* node, T value) {
    if (node == nullptr) {
        node = new Node<T>(value);
    }

    else if (value > node->info) {
        /* If value is greater than the current node, then it's at its right */
        node->right = insertNode(node->right, value);

        /* Updates the balance factor to selfbalance the tree */
        node = update_bf_right(node);
    }

    else {
        /* Checks if right is a nullptr and allocs memory if so */
        node->left = insertNode(node->left, value);

        /* Updates the balance factor to selfbalance the tree */
        node = update_bf_left(node);
    }

    return node;
}

template <typename T>
void Tree<T>::insert(T value) {
    root = insertNode(root, value);
}

template <typename T>
Node<T>* Tree<T>::removeNode(Node<T>* node, T target) {
    if (node == nullptr)
        return nullptr;

    else {
        if (node->info > target) {
            node->left = removeNode(node->left, target);

            node = update_bf_left(node);
        }

        else if (target > node->info) {
            node->right = removeNode(node->right, target);
            
            node = update_bf_right(node);
        }

        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }

            else if (node->left == nullptr) {
                Node<T>* aux = node;
                node = node->right;
                delete aux;
            }

            else if (node->right == nullptr) {
                Node<T>* aux = node;
                node = node->left;
                delete aux;
            }

            else {
                Node<T>* aux = node->left;

                while (aux->right != nullptr)
                    aux = aux->right;

                node->info = aux->info;
                node->left = removeNode(node->left, aux->info);
                node = update_bf_left(node);
            }
        }
    return node;
    }
}

template <typename T>
void Tree<T>::remove(T target) {
    root = removeNode (root, target);
}

template <typename T>
bool Tree<T>::searchNode(Node<T>* node, T value) {
    if (node == nullptr)
        return false;

    if (node->info > value)
        return searchNode(node->right, value);

    if (node->info < value)
        return searchNode(node->left, value);
    
    return true;
}

template <typename T>
bool Tree<T>::search(T value) {
    return searchNode (root, value);
}

template <typename T>
void Tree<T>::inOrder(Node<T>* node) {
    if (node == nullptr)
        return;

    inOrder (node->left);

    cout << node->info << " ";

    inOrder (node->right);
}

template <typename T>
void Tree<T>::print() {
    inOrder (root);

    cout << endl;
}

int main() {
    Tree<char> tree;

    tree.insert('A');
    tree.insert('C');
    tree.insert('D');
    tree.insert('E');
    tree.insert('B');

    tree.print();

    return 0;
}
