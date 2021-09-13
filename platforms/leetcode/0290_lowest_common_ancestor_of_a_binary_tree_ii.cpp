#include "../../template.hpp"

void preorder(TreeNode* root, vi& in, const int key) {
    if (not root) return;
    if (in.empty() or in.back() != key) in.push_back(root->val);
    preorder(root->left, in, key);
    preorder(root->right, in, key);
    if (in.back() != key) in.pop_back();
}

int sol(TreeNode* root, const int a, const int b) {
    vi in1, in2;
    preorder(root, in1, a);
    preorder(root, in2, b);

    if (in1.size() > in2.size()) swap(in1, in2);
    const int m = in1.size();
    const int n = in2.size();
    for (int i = 0, j = 0; i < m and j < n; ++i, ++j) {
        if (in1[i] != in2[j]) return in1[i - 1];
    }
    return in1.back();
}

int sol(const vi& arr, const int a, const int b) {
    return sol(TreeFromLevelOrder(arr), a, b);
}

int main() { TimeMeasure _; __x();
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 1) << endl; // 3
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 4) << endl; // 5
    cout << sol({1,2}, 1, 2) << endl; // 1
}
