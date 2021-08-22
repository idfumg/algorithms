#include "../../template.hpp"

int rec_(TreeNode* root) {
    if (not root) return 0;
    int ans = 0;
    if (root->val % 2 == 0) {
        ans =
            (root->left and root->left->left ? root->left->left->val : 0) +
            (root->left and root->left->right ? root->left->right->val : 0) +
            (root->right and root->right->left ? root->right->left->val : 0) +
            (root->right and root->right->right ? root->right->right->val : 0);
    }
    return ans + rec_(root->left) + rec_(root->right);
}

int rec(const vi& arr) {
    TreeNode* root = TreeFromLevelOrder(arr);
    return rec_(root);
}

int main() { TimeMeasure _; __x();
    cout << rec({6,7,8,2,7,1,3,9,-INF,1,4,-INF,-INF,-INF,5}) << endl; // 18
    cout << rec({1}) << endl; // 0
}
