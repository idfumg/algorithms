#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

Node* modify(Node* root) {
    if (not root) return nullptr;
    Node* left = modify(root->left);
    Node* right = modify(root->right);
    root->left = nullptr;
    root->right = left;
    Node* curr = root->right;
    while (curr and curr->right) curr = curr->right;
    if (curr) curr->right = right;
    return root;
}

int main() { TimeMeasure _; __x();
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \
    3     5
  */
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    modify(root);
    cout << root << endl; // 10 8 3 5 2
}
