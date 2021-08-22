#include "../../template.hpp"

ostream& operator<<(ostream& os, TreeNode* root) {
    print_inorder(root); return os;
}

void traverse(TreeNode* root, int& acc) {
    if (not root) return;
    traverse(root->right, acc);
    int temp = root->val;
    root->val += acc;
    acc += temp;
    traverse(root->left, acc);
}

TreeNode* tab_(TreeNode* root) {
    if (not root) return nullptr;
    int acc = 0;
    traverse(root, acc);
    return root;
}

TreeNode* tab(const vi& arr) {
    TreeNode* root = TreeFromLevelOrder(arr);
    return tab_(root);
}

int main() { TimeMeasure _; __x();
    cout << tab({4,1,6,0,2,5,7,-INF,-INF,-INF,3,-INF,-INF,-INF,8}) << endl; // 30,36,21,36,35,26,15,null,null,null,33,null,null,null,8
}
