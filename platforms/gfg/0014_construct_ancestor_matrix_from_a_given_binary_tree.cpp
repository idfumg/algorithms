#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

int get_max(Node* root) {
    if (not root) return -INF;
    return max({root->value, get_max(root->left), get_max(root->right)});
}

void preorder(Node* root, vi& arr, vvi& mat) {
    if (not root) return;
    for (int node : arr) {
        mat[node][root->value] = 1;
    }
    arr.push_back(root->value);
    preorder(root->left, arr, mat);
    preorder(root->right, arr, mat);
    arr.pop_back();
}

void construct(Node* root) {
    int n = get_max(root);
    vi arr;
    vvi mat(n + 1, vi(n + 1));
    preorder(root, arr, mat);
    cout << mat << endl;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(3);
    construct(root);
/*
0 0 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 1 1 0
*/
}
