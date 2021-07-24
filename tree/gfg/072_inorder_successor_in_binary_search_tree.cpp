#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root, int target, int& prev, int& ans) {
    if (not root) return;
    inorder(root->left, target, prev, ans);
    if (prev == target) ans = root->value;
    prev = root->value;
    inorder(root->right, target, prev, ans);
}

int InOrderSuccessor(Node* root, int target) {
    int prev = -INF, ans = -INF;
    inorder(root, target, prev, ans);
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root = nullptr;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    cout << InOrderSuccessor(root, 8) << endl; // 10
    cout << InOrderSuccessor(root, 10) << endl; // 12
    cout << InOrderSuccessor(root, 14) << endl; // 20
}
