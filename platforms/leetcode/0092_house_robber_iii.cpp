#include "../../template.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rec(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
    if (not root) return 0;
    if (dp.count(root)) return dp[root];
    return dp[root] = max(
        root->val +
        (root->left ? rec(root->left->left, dp) : 0) +
        (root->left ? rec(root->left->right, dp) : 0) +
        (root->right ? rec(root->right->left, dp) : 0) +
        (root->right ? rec(root->right->right, dp) : 0),

        rec(root->left, dp) + rec(root->right, dp));
}

int rec(TreeNode* root) {
    unordered_map<TreeNode*, int> dp;
    return rec(root, dp);
}

int main() { TimeMeasure _; __x();
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(1);
        cout << rec(root) << endl; // 7
    }

    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(1);
        cout << rec(root) << endl; // 9
    }
}
