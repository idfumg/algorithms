#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi in, int i, int j) {
    if (i > j) return nullptr;
    const auto idx = max_element(in.cbegin() + i, in.cbegin() + j + 1);
    int rootValue = *idx, k = distance(in.cbegin(), idx);
    Node* root = new Node(rootValue);
    root->left = construct(in, i, k - 1);
    root->right = construct(in, k + 1, j);
    return root;
}

void construct(vi in) {
    Node* root = construct(in, 0, in.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    construct({5, 10, 40, 30, 28}); // 5 10 40 30 28
    construct({1, 5, 10, 40, 30, 15, 28, 20}); // 1 5 10 40 30 15 28 20
}
