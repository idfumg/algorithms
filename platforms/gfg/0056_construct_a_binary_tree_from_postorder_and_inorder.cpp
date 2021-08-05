#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

Node* construct(vi in, vi post, int& idx, int i, int j) {
    if (i > j or idx < 0) return nullptr;
    int rootValue = post[idx--];
    int k = i;
    while (k <= j and in[k] != rootValue) ++k;
    Node* root = new Node(rootValue);
    root->right = construct(in, post, idx, k + 1, j);
    root->left = construct(in, post, idx, i, k - 1);
    return root;
}

void MakePreorder(vi in, vi post) {
    int idx = post.size() - 1;
    Node* root = construct(in, post, idx, 0, in.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = { 4, 8, 2, 5, 1, 6, 3, 7 };
    vi postorder = { 8, 4, 5, 2, 6, 7, 3, 1 };
    MakePreorder(inorder, postorder); // 1 2 4 8 5 3 6 7
}
