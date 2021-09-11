#include "../../template.hpp"

void traverse(TreeNode* root, unordered_map<int, int>& memo) {
    if (not root) return;
    ++memo[root->val];
    traverse(root->left, memo);
    traverse(root->right, memo);
}

bool traverse(TreeNode* root, unordered_map<int, int>& memo, const int k) {
    if (not root) return 0;
    const int d = k - root->val;
    if (memo.count(d)) {
        if (root->val == d) {
            if (memo[d] > 1) return 1;
        }
        else {
            return 1;
        }
    }
    return traverse(root->left, memo, k) or traverse(root->right, memo, k);
}

int sol(TreeNode* root, const int k) {
    if (not root) return 0;
    unordered_map<int, int> memo;
    traverse(root, memo);
    return traverse(root, memo, k);
}

int sol(const vi& arr, const int k) {
    return sol(TreeFromLevelOrder(arr), k);
}

int main() { TimeMeasure _; __x();
    cout << sol({5,3,6,2,4,-INF,7}, 9) << endl; // 1
    cout << sol({5,3,6,2,4,-INF,7}, 28) << endl; // 0
    cout << sol({2,1,3}, 4) << endl; // 1
    cout << sol({2,1,3}, 1) << endl; // 0
    cout << sol({2,1,3}, 3) << endl; // 1
    cout << sol({1}, 2) << endl; // 0
}
