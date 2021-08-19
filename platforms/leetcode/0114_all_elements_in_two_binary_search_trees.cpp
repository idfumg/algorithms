#include "../../template.hpp"

void inorder(TreeNode* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

vi tab_(TreeNode* root1, TreeNode* root2) {
    vi in1;
    inorder(root1, in1);
    vi in2;
    inorder(root2, in2);

    int m = in1.size();
    int n = in2.size();
    vi ans(m + n);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m and j < n) {
        if (in1[i] <= in2[j]) ans[k++] = in1[i++];
        else ans[k++] = in2[j++];
    }
    while (i < m) ans[k++] = in1[i++];
    while (j < n) ans[k++] = in2[j++];
    return ans;
}

vi tab(const vi& arr1, const vi& arr2) {
    TreeNode* root1 = TreeFromLevelOrder(arr1);
    TreeNode* root2 = TreeFromLevelOrder(arr2);
    return tab_(root1, root2);
}

int main() { TimeMeasure _; __x();
    cout << tab({2,1,4}, {1,0,3}) << endl; // 0,1,1,2,3,4
    cout << tab({0,-10,10}, {5,1,7,0,2}) << endl; // -10,0,0,1,2,5,7,10
    cout << tab({}, {5,1,7,0,2}) << endl; // 0,1,2,5,7
    cout << tab({0,-10,10}, {}) << endl; // -10,0,10
}
