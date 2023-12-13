#include <iostream>
#include <vector>

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
    void inOrderTraversal(Node* node, std::vector<int>& values);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val);
    void remove(int val);
    void insertFix(Node* z);
    void deleteFix(Node* x);
    void displayTree();
    int median();
};

void RedBlackTree::leftRotate(Node* x) {

}

void RedBlackTree::rightRotate(Node* y) {

}

void RedBlackTree::insertFixup(Node* z) {

}

void RedBlackTree::transplant(Node* u, Node* v) {
    
}

void RedBlackTree::deleteFixup(Node* x) {

}

void RedBlackTree::inOrderTraversal(Node* node, std::vector<int>& values) {
    if (node == nullptr)
        return;

    inOrderTraversal(node->left, values);
    values.push_back(node->data);
    inOrderTraversal(node->right, values);
}

void RedBlackTree::insert(int val) {
   
    insertFix(root); // Call the new insertFix method after insertion
}

void RedBlackTree::remove(int val) {
    
    deleteFix(root); // Call the new deleteFix method after deletion
}

void RedBlackTree::displayTree() {

}

int RedBlackTree::median() {
    std::vector<int> values;
    inOrderTraversal(root, values);

    int size = values.size();
    if (size == 0)
        return -1; // No median for an empty tree

    int middleIndex = size / 2;
    int medianValue = values[middleIndex];

    std::cout << medianValue << " is median" << std::endl;
    return medianValue;
}

int main() {
    int N;
    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    tree.displayTree();

    tree.median();

    return 0;
}
