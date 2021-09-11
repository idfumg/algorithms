#include "../../template.hpp"

int get_total(TreeNode* root) {
    if (not root) return 0;
    return root->val + get_total(root->left) + get_total(root->right);
}

int sum(TreeNode* root, const int total, ll& ans) {
    if (not root) return 0;
    const int left = sum(root->left, total, ans);
    const int right = sum(root->right, total, ans);
    ans = max(ans, 1ll * (total - left) * left);
    ans = max(ans, 1ll * (total - right) * right);
    return left + right + root->val;
}

int sol(TreeNode* root) {
    const int total = get_total(root);
    ll ans = 0;
    sum(root, total, ans);
    return ans % MOD;
}

int sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,4,5,6}) << endl; // 110
    cout << sol({1,-INF,2,3,4,-INF,-INF,5,6}) << endl; // 90
    cout << sol({2,3,9,10,7,8,6,5,4,11,1}) << endl; // 1025
    cout << sol({1,1}) << endl; // 1
    cout << sol({5,6,6,-INF,-INF,8,6,10,-INF,5}) << endl; // 504
}
