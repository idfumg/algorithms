#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi pre, vi preMirror, int& idx, int i, int j) {
    if (i > j or idx == pre.size()) return nullptr;
    int rootValue = pre[idx++];
    Node* root = new Node(rootValue);
    if (idx == pre.size()) return root;
    int k = i + 1;
    while (k <= j and preMirror[k] != pre[idx]) ++k;
    if (k == j + 1) return root;
    root->left = construct(pre, preMirror, idx, k, j);
    root->right = construct(pre, preMirror, idx, i, k - 1);
    return root;
}

Node* construct(vi pre, vi premirror) {
    int idx = 0;
    Node* root = construct(pre, premirror, idx, 0, pre.size() - 1);
    return root;
}

int main() { TimeMeasure _; __x();
    vi pre = {1,2,4,5,3,6,7};
    vi preMirror = {1,3,7,6,2,5,4};
    cout << construct(pre, preMirror) << endl; // 4 2 5 1 6 3 7
}
