#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void preorder(Node* root, int target, vi& arr) {
    if (not root) return;
    if (arr.empty() or arr.back() != target) arr.push_back(root->value);
    if (target < root->value) preorder(root->left, target, arr);
    if (target > root->value) preorder(root->right, target, arr);
    if (not arr.empty() and arr.back() != target) arr.pop_back();
}

int lca(Node* root, int a, int b) {
    vi arr1, arr2;
    preorder(root, a, arr1);
    preorder(root, b, arr2);
    if (arr1.empty() or arr2.empty()) return -1;
    if (arr1.size() > arr2.size()) swap(arr1, arr2);
    for (int i = 1; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) return arr1[i - 1];
    }
    return arr1.back();
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << lca(root, 10, 14) << endl; // 12
    cout << lca(root, 8, 14) << endl; // 8
    cout << lca(root, 10, 22) << endl; // 20
}
