#include "../../template.hpp"

using TreeNode = Node;

ostream& operator<<(ostream& os, TreeNode* root) { print_preorder(root); return os; }

TreeNode* construct(const vector<int>& nums, const int i, const int j) {
    if (i > j) return nullptr;
    int idx = i;
    for (int k = i; k <= j; ++k) {
        if (nums[k] > nums[idx]) {
            idx = k;
        }
    }
    TreeNode* root = new TreeNode(nums[idx]);
    root->left = construct(nums, i, idx - 1);
    root->right = construct(nums, idx + 1, j);
    return root;
}

TreeNode* construct(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    return construct(nums, 0, nums.size() - 1);
}

int main() { TimeMeasure _; __x();
    cout << construct({3,2,1,6,0,5}) << endl; // 6 3 2 1 5 0
}
