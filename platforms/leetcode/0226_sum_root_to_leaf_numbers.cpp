#include "../../template.hpp"

int traverse(TreeNode* root, const int current) {
    if (not root) return 0;
    if (not root->left and not root->right) return current * 10 + root->val;
    return
        traverse(root->left, current * 10 + root->val) +
        traverse(root->right, current * 10 + root->val);
}

int sol(TreeNode* root) {
    return traverse(root, 0);
}

int sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,2,3}) << endl; // 25
    cout << sol({4,9,0,5,1}) << endl; // 1026
    cout << sol({0,1}) << endl; // 1
}
