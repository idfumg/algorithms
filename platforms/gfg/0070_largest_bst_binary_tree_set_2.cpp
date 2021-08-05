#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, int& prev, int& ans, int& curr) {
    if (not root) return;
    inorder(root->left, prev, ans, curr);
    if (prev != -INF) {
        if (root->value > prev) ++curr;
        else curr = 1;
    }
    ans = max(ans, curr);
    prev = root->value;
    inorder(root->right, prev, ans, curr);
}

int LargestBSTinBT(Node* root) {
    int prev = -INF, ans = 1, curr = 1;
    inorder(root, prev, ans, curr);
    return ans;
}

int main() { TimeMeasure _; __x();
    /* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */

    Node* root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    cout << LargestBSTinBT(root) << endl; // 2
}
