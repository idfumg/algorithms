#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

bool convert(Node* root) {
    if (not root) return false;
    if (not root->left and not root->right) return root->value;
    return root->value = convert(root->left) & convert(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->left->left = new Node(0);
    root->left->right = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(1);

    cout << root << endl; // 0 1 1 0 1 0 1
    convert(root);
    cout << root << endl; // 0 0 1 0 1 1 1
}
