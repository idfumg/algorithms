#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

void inorder(Node* root, int& ans, int ancestor) {
    if (not root) return;
    ans = max(ans, ancestor - root->value);
    inorder(root->left, ans, max(ancestor, root->value));
    inorder(root->right, ans, max(ancestor, root->value));
}

int MaxDiff(Node* root) {
    int ans = 0;
    inorder(root, ans, root->value);
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << MaxDiff(root) << endl; // 7
}
