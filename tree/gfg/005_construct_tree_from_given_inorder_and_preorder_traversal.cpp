#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi in, vi pre, int& idx, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[idx++];
    int k = i;
    while (k <= j and in[k] != rootValue) ++k;
    Node* root = new Node(rootValue);
    root->left = construct(in, pre, idx, i, k - 1);
    root->right = construct(in, pre, idx, k + 1, j);
    return root;
}

void Build(vi in, vi pre) {
    int idx = 0;
    Node* root = construct(in, pre, idx, 0, in.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    vi preorder = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    Build(inorder, preorder); // 9 8 4 2 10 5 10 1 6 3 13 12 7
}
