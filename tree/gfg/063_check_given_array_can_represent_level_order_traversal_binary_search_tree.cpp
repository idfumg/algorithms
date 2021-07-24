#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

bool IsItLevelOrderOfBST(vi arr) {
    Node* root = nullptr;
    for (int value : arr) {
        root = insert(root, value);
    }

    int n = arr.size(), idx = 0;
    deque<Node*> q;
    q.push_back(root);
    while (not q.empty()) {
        Node* at = q.front(); q.pop_front();
        if (at->value != arr[idx++]) return false;
        if (at->left) q.push_back(at->left);
        if (at->right) q.push_back(at->right);
    }
    return true;
}

int main() { TimeMeasure _; __x();
    cout << IsItLevelOrderOfBST({7, 4, 12, 3, 6, 8, 1, 5, 10}) << endl; // 1
    cout << IsItLevelOrderOfBST({11, 6, 13, 5, 12, 10}) << endl; // 0
}
