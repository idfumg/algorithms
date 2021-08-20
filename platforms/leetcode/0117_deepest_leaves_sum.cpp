#include "../../template.hpp"

int height(TreeNode* root) {
    if (not root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int traverse(TreeNode* root, const int level, const int target_level) {
    if (not root) return 0;
    if (level == target_level) return root->val;
    return traverse(root->left, level + 1, target_level) + traverse(root->right, level + 1, target_level);
}

int tab_(TreeNode* root) {
    if (not root) return 0;
    return traverse(root, 1, height(root));
}

int tab(const vi& arr) {
    TreeNode* root = TreeFromLevelOrder(arr);
    return tab_(root);
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4,5,-INF,6,7,-INF,-INF,-INF,-INF,8}) << endl; // 15
    cout << tab({6,7,8,2,7,1,3,9,-INF,1,4,-INF,-INF,-INF,5}) << endl; // 19
}
