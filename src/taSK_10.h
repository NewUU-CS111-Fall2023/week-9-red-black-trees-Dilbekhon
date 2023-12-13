#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    void printInOrder(Node* node);
    int calculateHeight(Node* node);
    int calculateDepth(Node* node, int value);

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int value);
    void remove(int value);
    void print();
    int height();
    int depth(int value);
};

Node* BinarySearchTree::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

Node* BinarySearchTree::remove(Node* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->data)
        node->left = remove(node->left, value);
    else if (value > node->data)
        node->right = remove(node->right, value);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = node->right;
        while (temp->left != nullptr)
            temp = temp->left;

        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BinarySearchTree::printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}

int BinarySearchTree::calculateHeight(Node* node) {
    if (node == nullptr)
        return 0;

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

int BinarySearchTree::calculateDepth(Node* node, int value) {
    if (node == nullptr)
        return -1;

    if (value == node->data)
        return 0;
    else if (value < node->data)
        return calculateDepth(node->left, value) + 1;
    else
        return calculateDepth(node->right, value) + 1;
}

void BinarySearchTree::add(int value) {
    root = insert(root, value);
}

void BinarySearchTree::remove(int value) {
    root = remove(root, value);
}

void BinarySearchTree::print() {
    printInOrder(root);
    std::cout << std::endl;
}

int BinarySearchTree::height() {
    return calculateHeight(root);
}

int BinarySearchTree::depth(int value) {
    return calculateDepth(root, value);
}

int main() {
    int N;
    std::cin >> N;

    BinarySearchTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.add(value);
    }

    std::cout << "In-order traversal: ";
    tree.print();

    std::cout << "Height of the tree: " << tree.height() << std::endl;

    int valueToFindDepth;
    std::cin >> valueToFindDepth;
    int depth = tree.depth(valueToFindDepth);
    if (depth != -1)
        std::cout << "Depth of value " << valueToFindDepth << ": " << depth << std::endl;
    else
        std::cout << "Value " << valueToFindDepth << " not found in the tree." << std::endl;

    return 0;
}
