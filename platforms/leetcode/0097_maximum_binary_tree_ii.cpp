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

TreeNode* update(TreeNode* root, int val) {
    if (not root) return new TreeNode(val);
    if (val > root->value) {
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
    root->right = update(root->right, val);
    return root;
}

TreeNode* construct(const vector<int>& nums, const int val) {
    if (nums.empty()) return nullptr;
    TreeNode* root = construct(nums, 0, nums.size() - 1);
    return update(root, val);
}

int main() { TimeMeasure _; __x();
    cout << construct({1,4,2,3}, 5) << endl; // 5 4 1 3 2
    cout << construct({2,1,5,4}, 3) << endl; // 5 2 1 4 3
    cout << construct({2,1,5,3}, 4) << endl; // 5 2 1 4 3
}
