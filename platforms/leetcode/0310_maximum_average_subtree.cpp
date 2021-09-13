#include "../../template.hpp"

tuple<int, int> traverse(TreeNode* root, double& ans) {
    if (not root) return {0, 0};
    auto [left_sum, left_count] = traverse(root->left, ans);
    auto [right_sum, right_count] = traverse(root->right, ans);
    ans = max(ans, (double)left_sum / left_count);
    ans = max(ans, (double)right_sum / right_count);
    ans = max(ans, (double)(left_sum + right_sum + root->val) / (left_count + right_count + 1));
    return {left_sum + right_sum + root->val, left_count + right_count + 1};
}

double sol(TreeNode* root) {
    if (not root) return 0;
    double ans = 0;
    traverse(root, ans);
    return ans;
}

double sol(vi arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; __x();
    cout << sol({5,6,1}) << endl; // 6.00000
    cout << sol({0,null,1}) << endl; // 1.00000
}
