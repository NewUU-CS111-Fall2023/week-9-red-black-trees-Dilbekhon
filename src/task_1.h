#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    // Constructor
    Node(int key) : key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    // Helper functions
    void insertFixup(Node* node);
    void leftRotate(Node* node);
    void rightRotate(Node* node);

public:
    // Constructor
    RedBlackTree() : root(nullptr) {}

    // Public method to insert a value into the Red-Black tree
    void insert(int value);

    // Public method to print the Red-Black tree in inorder traversal
    void printInorder(Node* node);
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

void RedBlackTree::insertFixup(Node* node) {
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

void RedBlackTree::insert(int value) {
    Node* newNode = new Node(value);
    Node* parent = nullptr;
    Node* current = root;

    // Find the appropriate position to insert the new node
    while (current != nullptr) {
        parent = current;

        if (value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Set the parent of the new node
    newNode->parent = parent;

    // Insert the new node as a child of the parent
    if (parent == nullptr) {
        root = newNode;
    } else if (value < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Fix any violations of the Red-Black tree properties
    insertFixup(newNode);
}

void RedBlackTree::printInorder(Node* node) {
    if (node != nullptr) {
        printInorder(node->left);
        std::cout << node->key << " ";
        printInorder(node->right);
    }
}

int main() {
    RedBlackTree tree;

    // Insert nodes into the Red-Black tree
   I'm sorry, but I cannot complete the code as you have not provided the values to insert into the Red-Black tree. To complete the code and visualize the resulting tree after insertion, you would need to call the `insert` method of the `RedBlackTree` class with the desired values.

Here's an example of how you can complete the code to insert the values and visualize the resulting tree:

```cpp
int main() {
    RedBlackTree tree;

    // Insert nodes into the Red-Black tree
    tree.insert(9);
    tree.insert(3);
    tree.insert(10);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    tree.insert(5);
    tree.insert(7);
    tree.insert(4);

    // Print the resulting tree in inorder traversal
    tree.printInorder(tree.root);

    return 0;
}
