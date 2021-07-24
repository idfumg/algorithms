#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void normalize(Node* root, int diff) {
    for (; root; root = root->left) {
        root->value += diff;
    }
}

int modify(Node* root) {
    if (not root->left and not root->right) return root->value;
    int diff = modify(root->left) + modify(root->right);
    if (root->value < diff) root->value += diff - root->value;
    else if (root->value > diff) normalize(root->left, root->value - diff);
    return root->value;
}

void convert(Node* root) {
    modify(root);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    cout << root << endl; // 3 7 5 50 1 2 30
    convert(root);
    cout << root << endl; // 14 19 5 50 1 31 30
}
