#include "../../template.hpp"

void traverse(TreeNode* root, const int key, vector<TreeNode*>& in) {
    if (not root) return;
    if (in.empty() or in.back()->val != key) in.push_back(root);
    traverse(root->left, key, in);
    traverse(root->right, key, in);
    if (in.back()->val != key) in.pop_back();
}

TreeNode* sol(TreeNode* root, const int a, const int b) {
    if (not root) return 0;

    vector<TreeNode*> in1;
    traverse(root, a, in1);

    vector<TreeNode*> in2;
    traverse(root, b, in2);

    if (in1.size() > in2.size()) swap(in1, in2);

    const int m = in1.size();
    const int n = in2.size();
    for (int i = 0, j = 0; i < m and j < n; ++i, ++j) {
        if (in1[i]->val != in2[j]->val) {
            return in1[i - 1];
        }
    }
    return in1.back();
}

int sol(const vi& arr, const int a, const int b) {
    return sol(TreeFromLevelOrder(arr), a, b)->val;
}

int main() { TimeMeasure _; __x();
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 1) << endl; // 3
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 4) << endl; // 5
    cout << sol({1,2}, 1, 2) << endl; // 1
}
