#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

int traverse(Node* root, bool& isBalanced) {
    if (not root) return 0;
    int left = traverse(root->left, isBalanced) + 1;
    int right = traverse(root->right, isBalanced) + 1;
    if (max(left, right) > 2 * min(left, right)) isBalanced = false;
    return max(left, right);
}

bool IsBalanced(Node* root) {
    bool isBalanced = true;
    traverse(root, isBalanced);
    return isBalanced;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(12);
        root->right = new Node(14);
        root->right->right = new Node(16);
        cout << IsBalanced(root) << endl; // 0
    }
    {
        Node* root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(100);
        root->right->left = new Node(50);
        root->right->right = new Node(150);
        root->right->left->left = new Node(40);
        cout << IsBalanced(root) << endl; // 1
    }
    {
        Node* root = new Node(40);
        root->left = new Node(10);
        root->right = new Node(100);
        root->right->left = new Node(60);
        root->right->right = new Node(150);
        cout << IsBalanced(root) << endl; // 1
    }
}
