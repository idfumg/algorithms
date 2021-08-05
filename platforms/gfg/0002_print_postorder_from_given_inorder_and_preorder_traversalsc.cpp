#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_postorder(root); return os; }

Node* construct(vi in, vi pre, unordered_map<int, int>& tab, int& idx, int i, int j) {
    if (i > j or idx == in.size()) return nullptr;
    int rootValue = pre[idx++];
    int k = tab[rootValue];
    Node* root = new Node(rootValue);
    root->left = construct(in, pre, tab, idx, i, k - 1);
    root->right = construct(in, pre, tab, idx, k + 1, j);
    return root;
}

void PostorderTraversal(vi in, vi pre) {
    unordered_map<int, int> tab;
    for (int i = 0; i < in.size(); ++i) {
        tab[in[i]] = i;
    }
    int idx = 0;
    Node* root = construct(in, pre, tab, idx, 0, in.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = {4, 2, 5, 1, 3, 6};
    vi preorder = {1, 2, 4, 5, 3, 6};
    PostorderTraversal(inorder, preorder); // 4 5 2 6 3 1
}
