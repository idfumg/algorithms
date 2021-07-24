#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

void inorder(Node* root, vi& arr, int& idx) {
    if (not root) return;
    inorder(root->left, arr, idx);
    root->value = 0;
    if (idx > 0) root->value = arr[idx - 1];
    if (idx < arr.size()) root->value += arr[idx + 1];
    ++idx;
    inorder(root->right, arr, idx);
}

void ReplaceNodeWithSum(Node* root) {
    vi arr;
    inorder(root, arr);

    int idx = 0;
    inorder(root, arr, idx);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << root << endl; // 1 2 4 5 3 6 7
    ReplaceNodeWithSum(root);
    cout << root << endl; // 11 9 2 3 13 4 3
}
