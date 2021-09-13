#include "../../template.hpp"

TreeNode* sol(TreeNode* root, const int value) {
    if (not root) return new TreeNode(value);
    if (value < root->val) root->left = sol(root->left, value);
    else root->right = sol(root->right, value);
    return root;
}

TreeNode* sol(const vi& arr, const int value) {
    return sol(TreeFromLevelOrder(arr), value);
}

ostream& operator<<(ostream& os, TreeNode* root) {
    print_inorder(root); return os;
}

int main() { TimeMeasure _; __x();
    cout << sol({4,2,7,1,3}, 5) << endl; // 1 2 3 4 5 7
    cout << sol({40,20,60,10,30,50,70}, 25) << endl; // 10 20 25 30 40 50 60 70
    cout << sol({4,2,7,1,3,-INF,-INF,-INF,-INF,-INF,-INF}, 5) << endl; // 1 2 3 4 5 7
}
