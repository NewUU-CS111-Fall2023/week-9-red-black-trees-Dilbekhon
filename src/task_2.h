#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, Color c, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr)
        : data(val), color(c), left(l), right(r), parent(p) {}
};

class RedBlackTree {
private:
    Node* root;

    // Helper functions
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void insertFixup(Node* z);
    void transplant(Node* u, Node* v);
    void deleteFixup(Node* x);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val);
    void remove(int val);
    void printTree(Node* root, int indent = 0);
};

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertFixup(Node* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
}

void RedBlackTree::deleteFixup(Node* x) {
    while (x != root && (x == nullptr || x->color == BLACK)) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == BLACK) {
                    if (w->left != nullptr)
                        w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != nullptr)
                    w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == BLACK) {
                    if (w->right != nullptr)
                        w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != nullptr)
                    w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr)
        x->color = BLACK;
}

void RedBlackTree::insert(int val) {
    Node* z = new Node(val, RED);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == nullptr)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    insertFixup(z);
}

void RedBlackTree::remove(int val) {

}

