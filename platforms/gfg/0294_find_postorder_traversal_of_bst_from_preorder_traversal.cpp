#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_postorder(root); return os; }

Node* construct(vi pre, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[i];
    int k = i + 1;
    while (k <= j and pre[k] < rootValue) ++k;
    Node* root = new Node(rootValue);
    root->left = construct(pre, i + 1, k - 1);
    if (k <= j) {
        root->right = construct(pre, k, j);
    }
    return root;
}

void PostorderFromPreorder(vi pre) {
    Node* root = construct(pre, 0, pre.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    PostorderFromPreorder({40, 30, 35, 80, 100}); // 35 30 100 80 40
    PostorderFromPreorder({40, 30, 32, 35, 80, 90, 100, 120}); // 35 32 30 120 100 90 80 40
}
