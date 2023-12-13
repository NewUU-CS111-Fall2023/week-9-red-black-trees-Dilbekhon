#include <iostream>
#include <queue>

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
    void printTree(Node* root, int indent = 0);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val);
    void remove(int val);
    void insertFix(Node* z);
    void deleteFix(Node* x);
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

void RedBlackTree::deleteFixup(Node* x) {
  
}

void RedBlackTree::insert(int val) {
 
    insertFix(root); // Call the new insertFix method after insertion
}

void RedBlackTree::remove(int val) {
  
    deleteFix(root); 
}

void RedBlackTree::insertFix(Node* z) {
  
    while (z->parent != nullptr && z->parent->color == RED) {
        // ... (same as before)
    }
    root->color = BLACK;
}

void RedBlackTree::deleteFix(Node* x) {
    while (x != root && (x == nullptr || x->color == BLACK)) {
        // ... (same as before)
    }
    if (x != nullptr)
        x->color = BLACK;
}

void RedBlackTree::displayTree() {
    printTree(root);
}

void RedBlackTree::printTree(Node* root, int indent) {
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            for (int j = 0; j < indent; j++)
                std::cout << " ";

            std::cout << "(" << current->data << "(" << (current->color == RED ? "RED" : "BLACK") << "))";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }

        std::cout << std::endl;
        indent += 2;
    }
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

    int deleteValue;
    std::cin >> deleteValue;
    tree.remove(deleteValue);

    tree.displayTree();

    return 0;
}
