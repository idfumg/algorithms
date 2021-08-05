#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

int sum(Node* root) {
    if (not root) return 0;
    return root->value + sum(root->left) + sum(root->right);
}

int convert(Node* root) {
    if (not root) return 0;
    root->value += sum(root->left);
    convert(root->left);
    convert(root->right);
    return root->value;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    convert(root);
    cout << root << endl; // 4 6 5 12 3 6
}
