#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi pre, vi preln, int& idx) {
    if (idx == pre.size()) return nullptr;
    if (preln[idx] == 'L') return new Node(pre[idx++]);
    int rootValue = pre[idx++];
    Node* root = new Node(rootValue);
    root->left = construct(pre, preln, idx);
    root->right = construct(pre, preln, idx);
    return root;
}

Node* construct(vi pre, vi preln) {
    int idx = 0;
    Node* root = construct(pre, preln, idx);
    return root;
}

int main() { TimeMeasure _; __x();
    vi pre = {10, 30, 20, 5, 15};
    vi preln = {'N', 'N', 'L', 'L', 'L'};
    cout << construct(pre, preln) << endl; // 20 30 5 10 15
}
