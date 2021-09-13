#include "../../template.hpp"

int sol(TreeNode* root) {
    if (not root) return 0;
    deque<TreeNode*> q;
    q.push_back(root);
    int ans = 1;
    int maxi = root->val;
    int level = 1;
    while (not q.empty()) {
        int n = q.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += q[i]->val;
        }
        if (maxi < sum) {
            maxi = sum;
            ans = level;
        }
        ++level;
        while (n--) {
            TreeNode* at = q.front(); q.pop_front();
            if (at->left) q.push_back(at->left);
            if (at->right) q.push_back(at->right);
        }
    }
    return ans;
}

int sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

int main() { TimeMeasure _; __x();
    cout << sol({1,7,0,7,-8,-INF,-INF}) << endl; // 2
    cout << sol({989,-INF,10250,98693,-89388,-INF,-INF,-INF,-32127}) << endl; // 2
}
