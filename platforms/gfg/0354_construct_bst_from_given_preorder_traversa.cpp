#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi pre, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[i];
    int k = i + 1;
    for (; k <= j and pre[k] < rootValue; ++k) {}
    Node* root = new Node(rootValue);
    root->left = construct(pre, i + 1, k - 1);
    root->right = construct(pre, k, j);
    return root;
}

Node* ConstructFromPreorder(vi pre) {
    Node* root = construct(pre, 0, pre.size() - 1);
    return root;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = ConstructFromPreorder({40, 30, 35, 80, 100});
        cout << root << endl; // 30 35 40 80 100
    }
    {
        Node* root = ConstructFromPreorder({40, 30, 32, 35, 80, 90, 100, 120});
        cout << root << endl; // 30 32 35 40 80 90 100 120
    }
}
