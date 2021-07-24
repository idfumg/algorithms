#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void go_left(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) return;
    cout << root->value << ' ';
    go_left(root->left);
}

void go_right(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) return;
    go_right(root->right);
    cout << root->value << ' ';
}

void go_leaves(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) cout << root->value << ' ';
    go_leaves(root->left);
    go_leaves(root->right);
}

void PrintBoundary(Node* root) {
    go_left(root);
    go_leaves(root);
    go_right(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    PrintBoundary(root); // 20 8 4 10 14 25 22
}
