#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}

    // Set left node
    void setLeft(Node* node) {
        left = node;
    }

    // Set right node
    void setRight(Node* node) {
        right = node;
    }

    // Get left node
    Node* getLeft() {
        return left;
    }

    // Get right node
    Node* getRight() {
        return right;
    }

    // Set data of node
    void setData(int data) {
        this->data = data;
    }

    // Get data of node
    int getData() {
        return data;
    }
};

// Traverse left, then print its data, and then traverse for the rightmost node
void inorder(Node* tree) {
    if (tree) {
        inorder(tree->getLeft());
        cout << tree->getData() << " ";
        inorder(tree->getRight());
    }
}

// Print the root node, traverse left, then right
void preorder(Node* tree) {
    if (tree) {
        cout << tree->getData() << " ";
        preorder(tree->getLeft());
        preorder(tree->getRight());
    }
}

// Traverse left, right, and print data
void postorder(Node* tree) {
    if (tree) {
        postorder(tree->getLeft());
        postorder(tree->getRight());
        cout << tree->getData() << " ";
    }
}

// Draw the tree structure
void drawTree(Node* tree, int space = 0) {
    const int spacing = 5;

    if (tree == nullptr)
        return;

    space += spacing;

    drawTree(tree->getRight(), space);

    cout << endl;
    for (int i = spacing; i < space; i++)
        cout << " ";

    cout << tree->getData() << "\n";

    drawTree(tree->getLeft(), space);
}

int main() {
    // Create the tree
    Node* root = new Node(1);
    root->setLeft(new Node(2));
    root->setRight(new Node(3));
    root->getLeft()->setLeft(new Node(4));

    // Draw the tree structure
    cout << "Tree Structure:\n";
    drawTree(root);

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);

    // Deallocate memory
    delete root->getLeft()->getLeft();
    delete root->getLeft();
    delete root->getRight();
    delete root;

    return 0;
}


/*
Output:
Tree Structure:

     3

1

     2

          4

Inorder Traversal: 4 2 1 3 
Preorder Traversal: 1 2 4 3 
Postorder Traversal: 4 2 3 1 
  */
