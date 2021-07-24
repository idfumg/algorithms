#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    for (Node* curr = root; curr;) {
        if (value < curr->value and not curr->left) {
            curr->left = new Node(value);
            return root;
        }
        else if (value > curr->value and not curr->right) {
            curr->right = new Node(value);
            return root;
        }
        else if (value < curr->value) curr = curr->left;
        else if (value > curr->value) curr = curr->right;
        else return root;
    }
    return root;
}

void inorder(Node* root, vi arr, int& idx) {
    if (not root) return;
    inorder(root->left, arr, idx);
    if (root->value == arr[idx]) ++idx;
    inorder(root->right, arr, idx);
}

bool IsSequenceExist(Node* root, vi arr) {
    int idx = 0;
    inorder(root, arr, idx);
    return idx == arr.size();
}

int main() { TimeMeasure _; __x();
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    cout << IsSequenceExist(root, {4, 6, 8, 14}) << endl; // 1
    cout << IsSequenceExist(root, {4, 6, 8, 12, 13}) << endl; // 0
}
