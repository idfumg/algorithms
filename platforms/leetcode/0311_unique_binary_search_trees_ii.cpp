#include "../../template.hpp"

ostream& operator<<(ostream& os, TreeNode* root) {
    print_inorder(root); return os;
}

vector<TreeNode*> construct(int i, int j) {
    if (i > j) return {nullptr};

    vector<TreeNode*> ans;
    for (int k = i; k <= j; ++k) {
        const auto possible_lefts = construct(i, k - 1);
        const auto possible_rights = construct(k + 1, j);
        for (const auto left : possible_lefts) {
            for (const auto right : possible_rights) {
                TreeNode* root = new TreeNode(k);
                root->left = left;
                root->right = right;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode*> sol(int n) {
    return construct(1, n);
}

int main() { TimeMeasure _; __x();
    cout << sol(3) << endl; // [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
    cout << sol(1) << endl; // [[1]]
}
