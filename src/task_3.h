
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int key) : key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void insertFix(Node* node);
    void deleteFix(Node* node);
    void leftRotate(Node* node);
    void rightRotate(Node* node);
    void transplant(Node* u, Node* v);
    Node* minimumNode(Node* node) const;
    void printTreeHelper(Node* node, int indent = 0) const;

public:

    RedBlackTree() : root(nullptr) {}

    ~RedBlackTree();

    void insert(int value);
    void remove(int value);
    void printTree() const;
};

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;

    if (y->right != nullptr) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void RedBlackTree::insertFix(Node* node) {
    while (node->parent != nullptr && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;

            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;

            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::deleteFix(Node* node) {
    while (node != root && (node == nullptr || node->color == BLACK)) {
        if (node == node->parent->left) {
            Node* sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                leftRotate(node->parent);
                sibling = node->parent->right;
            }

            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (sibling->right == nullptr || sibling->right->color == BLACK) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = BLACK;
                    }

                    sibling->color = RED;
                    rightRotate(sibling);
                    sibling = node->parent->right;
                }
