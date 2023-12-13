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

    void insertFixup(Node* node);
    void leftRotate(Node* node);
    void rightRotate(Node* node);

public:

    RedBlackTree() : root(nullptr) {}

    void insert(int value);

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

    while (current != nullptr) {
        parent = current;

        if (value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (parent == nullptr) {
        root = newNode;
    } else if (value < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

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

   I'm sorry, but I cannot complete the code as you have not provided the values to insert into the Red-Black tree. To complete the code and visualize the resulting tree after insertion, you would need to call the `insert` method of the `RedBlackTree` class with the desired values.

Here's an example of how you can complete the code to insert the values and visualize the resulting tree:

```cpp
int main() {
    RedBlackTree tree;

    tree.insert(9);
    tree.insert(3);
    tree.insert(10);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    tree.insert(5);
    tree.insert(7);
    tree.insert(4);

    tree.printInorder(tree.root);

    return 0;
}


// task 2 
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, Color c)
        : data(val), color(c), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void insertFixup(Node* z);
    void transplant(Node* u, Node* v);
    void printTree(Node* root, int space);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val);
    void displayTree();
};

void RedBlackTree::leftRotate(Node* x) {

}

void RedBlackTree::rightRotate(Node* y) {

}

void RedBlackTree::insertFixup(Node* z) {

}

void RedBlackTree::transplant(Node* u, Node* v) {

}

void RedBlackTree::insert(int val) {

}

void RedBlackTree::displayTree() {
    printTree(root, 0);
}

void RedBlackTree::printTree(Node* root, int space) {
    if (root == nullptr)
        return;

    const int count = 5;
    space += count;

    printTree(root->right, space);

    std::cout << std::endl;
    for (int i = count; i < space; i++)
        std::cout << " ";
    std::cout << root->data << std::endl;

    printTree(root->left, space);
}

int main() {
    RedBlackTree tree;

    tree.insert(12);
    tree.insert(8);
    tree.insert(18);
    tree.insert(5);
    tree.insert(11);
    tree.insert(17);
    tree.insert(4);

    tree.displayTree();

    return 0;
}

