#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

void preorder(Node* root, vi& arr, int& idx) {
    if (not root) return;
    root->value = arr[idx++];
    preorder(root->left, arr, idx);
    preorder(root->right, arr, idx);
}

void ConvertToMinHeap(Node* root) {
    vi arr;
    inorder(root, arr);

    int idx = 0;
    preorder(root, arr, idx);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    ConvertToMinHeap(root);
    cout << root << endl; // 1 2 3 4 5 6 7
}
