#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vi arr, int rootIdx) {
    Node* root = new Node(rootIdx);
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == root->value) {
            if (not root->left) root->left = construct(arr, i);
            else if (not root->right) root->right = construct(arr, i);
        }
    }
    return root;
}

void construct(vi arr) {
    const auto it = find(arr.begin(), arr.end(), -1);
    Node* root = construct(arr, distance(arr.begin(), it));
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    construct({1, 5, 5, 2, 2, -1, 3}); // 0 1 5 6 3 2 4
    construct({-1, 0, 0, 1, 1, 3, 5}); // 6 5 3 1 4 0 2
}
