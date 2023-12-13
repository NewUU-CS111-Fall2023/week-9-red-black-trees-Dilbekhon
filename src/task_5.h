#include <iostream>
#include <unordered_map>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Helper functions
    Node* insert(Node* node, int value);
    void countChildren(Node* node, std::unordered_map<int, int>& childCount);

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value);
    void displayChildCount();
};

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

void BinaryTree::countChildren(Node* node, std::unordered_map<int, int>& childCount) {
    if (node == nullptr)
        return;

    int count = 0;
    if (node->left != nullptr)
        count++;
    if (node->right != nullptr)
        count++;

    childCount[node->value] = count;

    countChildren(node->left, childCount);
    countChildren(node->right, childCount);
}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

void BinaryTree::displayChildCount() {
    std::unordered_map<int, int> childCount;
    countChildren(root, childCount);

    for (auto& entry : childCount) {
        std::cout << entry.first << " - " << entry.second << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;

    BinaryTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    tree.displayChildCount();

    return 0;
}
