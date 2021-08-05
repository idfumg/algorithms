#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, int& k) {
    if (not root) return;
    inorder(root->left, k);
    if (k-- == 1) cout << root->value << endl;
    inorder(root->right, k);
}

void NthInorder(Node* root, int k) {
    inorder(root, k);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(10);
        root->left = new Node(20);
        root->right = new Node(30);
        root->left->left = new Node(40);
        root->left->right = new Node(50);

        NthInorder(root, 4); // 10
    }
    {
        Node* root = new Node(7);
        root->left = new Node(2);
        root->right = new Node(3);
        root->right->left = new Node(8);
        root->right->right = new Node(5);
        NthInorder(root, 3); // 8
    }
}
