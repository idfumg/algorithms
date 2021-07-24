#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

int height(Node* root) {
    if (not root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool IsBalanced(Node* root) {
    if (not root) return true;
    int left = height(root->left);
    int right = height(root->right);
    return abs(left - right) <= 1 and IsBalanced(root->left) and IsBalanced(root->right);
}

int main() { TimeMeasure _; __x();
    /* Constructed binary tree is
       1
     /   \
    2     3
   / \   /
  4   5 6
 /
7
*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);

    root->right = new Node(3);
    root->right->left = new Node(6);

    cout << IsBalanced(root) << endl; // 1
}
