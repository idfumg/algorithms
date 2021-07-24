#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

void inorder(Node* root, vi& arr, int& idx) {
    if (not root) return;
    inorder(root->left, arr, idx);
    root->value = arr[idx++];
    inorder(root->right, arr, idx);
}

void BinaryTreeToBST(Node* root) {
    vi arr;
    inorder(root, arr);

    sort(arr.begin(), arr.end());

    int idx = 0;
    inorder(root, arr, idx);
}

int main() { TimeMeasure _; __x();
    /* Constructing tree given in the above figure
    10
   /  \
  30   15
 /      \
20       5*/

    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    cout << root << endl; // 20 30 10 15 5
    BinaryTreeToBST(root);
    cout << root << endl; // 5 10 15 20 30
}
