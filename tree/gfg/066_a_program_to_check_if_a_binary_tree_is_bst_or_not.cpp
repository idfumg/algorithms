#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

bool IsBST(Node* root, int low, int high) {
    if (not root) return true;
    if (root->value <= low or root->value >= high) return false;
    return IsBST(root->left, low, root->value) and IsBST(root->right, root->value, high);
}

bool IsBST(Node* root) {
    return IsBST(root, -INF, +INF);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(4);
        root->left = new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        cout << IsBST(root) << endl; // 1
    }
    {
        Node* root = new Node(3);
        root->left = new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(1);
        root->left->right = new Node(4);
        cout << IsBST(root) << endl; // 0
    }
}
