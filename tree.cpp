#include <iostream>
using namespace std;

// Tree Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// In-order Traversal (Left-Root-Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order Traversal (Root-Left-Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order Traversal (Left-Right-Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Manually building the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "In-order: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}
