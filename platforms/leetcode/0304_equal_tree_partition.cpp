#include "../../template.hpp"

int traverse_total_sum(TreeNode* root) {
    if (not root) return 0;
    return root->val + traverse_total_sum(root->left) + traverse_total_sum(root->right);
}

int find_weak_spot(TreeNode* root, const int total, int& ans) {
    if (not root) return 0;
    const int left = find_weak_spot(root->left, total, ans);
    const int right = find_weak_spot(root->right, total, ans);
    if (root->left and left * 2 == total) ans = 1;
    if (root->right and right * 2 == total) ans = 1;
    return root->val + left + right;
}

int sol(TreeNode* root) {
    const int total = traverse_total_sum(root);
    int ans = 0;
    find_weak_spot(root, total, ans);
    return ans;
}

int sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; __x();
    cout << sol({5,10,10,null,null,2,3}) << endl; // 1
    cout << sol({1,2,10,null,null,2,20}) << endl; // 0
    cout << sol({0,-1,1}) << endl; // 0
    cout << sol({-1,1}) << endl; // 0
    cout << sol({1,-1}) << endl; // 0
}
