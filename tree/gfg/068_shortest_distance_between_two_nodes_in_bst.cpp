#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

void preorder(Node* root, int target, vi& arr) {
    if (not root) return;
    if (arr.empty() or arr.back() != target) arr.push_back(root->value);
    preorder(root->left, target, arr);
    preorder(root->right, target, arr);
    if (not arr.empty() and arr.back() != target) arr.pop_back();
}

int FindDistance(Node* root, int a, int b) {
    vi arr1, arr2;
    preorder(root, a, arr1);
    preorder(root, b, arr2);
    if (arr1.empty() or arr2.empty()) return - 1;
    if (arr1.size() > arr2.size()) swap(arr1, arr2);
    for (int i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) return arr1.size() - i + arr2.size() - i;
    }
    return arr2.size() - arr1.size();
}

int main() { TimeMeasure _; __x();
    {
        Node* root = nullptr;
        root = insert(root, 20);
        root = insert(root, 10);
        root = insert(root, 5);
        root = insert(root, 15);
        root = insert(root, 30);
        root = insert(root, 25);
        root = insert(root, 35);
        cout << FindDistance(root, 5, 35) << endl; // 4
    }
    {
        Node* root = new Node(5);
        root->left = new Node(2);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        root->right = new Node(12);
        root->right->left = new Node(9);
        root->right->right = new Node(21);
        root->right->right->left = new Node(19);
        root->right->right->right = new Node(25);
        cout << FindDistance(root, 3, 9) << endl; // 4
        cout << FindDistance(root, 9, 25) << endl; // 3
        cout << FindDistance(root, 12, 21) << endl; // 1
    }
}
