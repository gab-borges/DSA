#include "avl_tree.hpp"

int Tree::getHeight(const unique_ptr<Node>& node) const {
    return (node ? node->height : -1);
}

int Tree::balance(const unique_ptr<Node>& node) const {
    return getHeight(node->right) - getHeight(node->left);
}

void Tree::update_height() {
    height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

void Node::print() {
    cout << info << endl;
    
    if (left != nullptr)
        left->print();

    if (right != nullptr)
        right->print();
}

Tree* Tree::simple_left() {
    Tree* aux = right;
    right = aux->left;
    aux->left = this;

    return aux;
}

Tree* Tree::simple_right() {
    Tree* aux = left;
    left = aux->right;
    aux->right = this;

    return aux;
}

Tree* Tree::double_left() {
    right = right->simple_right();

    return simple_left();
}

Tree* Tree::double_right() {
    left = left->simple_left();

    return simple_right();
}

Tree* Tree::update_bf_left() {
    this->update_height();

    if (this->balance() == -2) {
        if (left->balance() <= 0)
            this = this->simple_right();

        else
            this = this->double_right();
    }

    return this;
}

Tree* Tree::update_bf_right() {
    this->update_height();

    if (this->balance() == 2) {
        if (right->balance() >= 0)
            this = this->simple_left();

        else
            this = this->double_left();
    }

    return this;
}

Tree* Tree::insert(char newData) {
    if (newData > info) {
        /* Checks if right is a nullptr and allocs memory if so */
        right = right ? right->insert(newData) : new Tree(newData);

        /* Updates the balance factor to selfbalance the tree */
        this = this->update_bf_right();

        return right;
    }

    else {
        /* Checks if right is a nullptr and allocs memory if so */
        left = left ? left->insert(newData) : new Tree(newData);

        /* Updates the balance factor to selfbalance the tree */
        this = this->update_bf_left();

        return left;
    }
}

Tree* Tree::remove(char target) {
    if (info < target) {
        left = left->remove(target);

        this = this->update_bf_left();
    }

    else if (target < info) {
        right = right->remove(target);
        
        this = this->update_bf_right();
    }

    else {
        if (left == nullptr && right == nullptr) {
            delete this;
            this = nullptr;
        }

        else if (left == nullptr) {
            Tree* aux = this;
            this = right;
            delete aux;
        }

        else if (right == nullptr) {
            Tree* aux = this;
            this = left;
            delete aux;
        }

        else {
            Tree* aux = left;

            while (aux->right)
                aux = aux->right;
            
            this->info = aux->info;
            left = left->remove(aux->info);
            this = this->update_bf_left();
        }

        return this;
    }

    return this;
}

int main() {
    cout << "Hello World" << endl;

    return 0;
}