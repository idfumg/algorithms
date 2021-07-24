#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void mirror(Node* root) {
    if (not root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << root << endl; // 4 2 5 1 3
    mirror(root);
    cout << root << endl; // 3 1 5 2 4
}
