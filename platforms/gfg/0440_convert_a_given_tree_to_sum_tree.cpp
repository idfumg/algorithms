#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

int convert(Node* root) {
    if (not root) {
        return 0;
    }
    if (not root->left and not root->right) {
        int res = root->value;
        root->value = 0;
        return res;
    }
    int res = root->value;
    root->value = convert(root->left) + convert(root->right);
    return res + root->value;
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    convert(root);
    cout << root << endl; // 0 4 0 20 0 12 0
}
