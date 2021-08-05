#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi pre, vi post, int& idx, int i, int j) {
    if (i > j or idx == pre.size()) return nullptr;
    int rootValue = pre[idx++];
    if (idx == pre.size()) return new Node(rootValue);
    int k = i;
    while (k <= j and post[k] != pre[idx]) ++k;
    Node* root = new Node(rootValue);
    if (k == j + 1) return root;
    root->left = construct(pre, post, idx, i, k);
    root->right = construct(pre, post, idx, k + 1, j);
    return root;
}

Node* construct(vi pre, vi post) {
    int idx = 0;
    Node* root = construct(pre, post, idx, 0, post.size() - 1);
    return root;
}

int main() { TimeMeasure _; __x();
    Node* root = construct({1, 2, 4, 8, 9, 5, 3, 6, 7}, {8, 9, 4, 5, 2, 6, 7, 3, 1});
    cout << root << endl; // // 8 4 9 2 5 1 6 3 7
}
