#include "../../template.hpp"

void traverse(TreeNode* root, string& ans, string& current) {
    if (not root) return;
    current.push_back(root->val + 'a');
    if (not root->left and not root->right) {
        reverse(current.begin(), current.end());
        if (ans.empty() or current < ans) {
            ans = current;
        }
        reverse(current.begin(), current.end());
    }
    traverse(root->left, ans, current);
    traverse(root->right, ans, current);
    current.pop_back();
}

string sol(TreeNode* root) {
    string current;
    string ans;
    traverse(root, ans, current);
    return ans;
}

string sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; //__x();
    cout << sol({0,1,2,3,4,3,4}) << endl; // dba
    cout << sol({25,1,3,1,3,0,2}) << endl; // adz
    cout << sol({2,2,1,-INF,1,0,-INF,0}) << endl; // abc
}
