#include <iostream>
#include <unordered_map>

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

    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void insertFixup(Node* z);
    void transplant(Node* u, Node* v);
    void deleteFixup(Node* x);
    void countChildren(Node* node, std::unordered_map<int, int>& childCount);
    int searchValue(Node* node, int value, int height);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val);
    void remove(int val);
    void printTree(Node* root, int indent = 0);
    void displayChildCount();
    void search(int value);
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

void RedBlackTree::countChildren(Node* node, std::unordered_map<int, int>& childCount) {
  
}

int RedBlackTree::searchValue(Node* node, int value, int height) {
    if (node == nullptr)
        return -1;

    if (value < node->data) {
        return searchValue(node->left, value, height + 1);
    } else if (value > node->data) {
        return searchValue(node->right, value, height + 1);
    } else {
        std::cout << value << " is found, its height is " << height << std::endl;
        return height;
    }
}

void RedBlackTree::search(int value) {
    int height = searchValue(root, value, 1);
    if (height == -1)
        std::cout << value << " is not found" << std::endl;
}

void RedBlackTree::insert(int val) {
  
}

void RedBlackTree::remove(int val) {
   
}

void RedBlackTree::printTree(Node* root, int indent) {
}

void RedBlackTree::displayChildCount() {

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

    tree.displayChildCount();

    int searchValue;
    std::cin >> searchValue;

    tree.search(searchValue);

    return 0;
}
