#include "../../template.hpp"

int height(TreeNode* root, int& d) {
    if (not root) return 0;
    const int left = height(root->left, d);
    const int right = height(root->right, d);
    d = max(d, left + right);
    return max(left, right) + 1;
}

int sol(TreeNode* root) {
    int d = 0;
    height(root, d);
    return d;
}

int sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,4,5}) << endl; // 3
    cout << sol({1,2}) << endl; // 1
}
