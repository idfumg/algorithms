#include "../../template.hpp"

void collect_values(TreeNode* root, unordered_set<int>& values) {
    if (not root) return;
    values.insert(root->val);
    collect_values(root->left, values);
    collect_values(root->right, values);
}

bool find_pair(TreeNode* root, const int target, const unordered_set<int>& values) {
    if (not root) return false;
    if (values.count(target - root->val)) return true;
    return find_pair(root->left, target, values) or find_pair(root->right, target, values);
}

int sol(TreeNode* root1, TreeNode* root2, const int target) {
    unordered_set<int> values;
    collect_values(root1, values);
    return find_pair(root2, target, values);
}

int sol(const vi& arr1, const vi& arr2, const int target) {
    return sol(TreeFromLevelOrder(arr1), TreeFromLevelOrder(arr2), target);
}

int sol2(TreeNode* root1, TreeNode* root2, const int target) {
    stack<TreeNode*> stack1, stack2;
    while (true) {
        for (; root1; root1 = root1->left) stack1.push(root1);
        for (; root2; root2 = root2->right) stack2.push(root2);
        if (stack1.empty() or stack2.empty()) return false;
        TreeNode* left = stack1.top();
        TreeNode* right = stack2.top();
        if (left->val + right->val == target) return true;
        if (left->val + right->val < target) {
            root1 = stack1.top()->right;
            stack1.pop();
        }
        else {
            root2 = stack2.top()->left;
            stack2.pop();
        }
    }
    return false;
}

int sol2(const vi& arr1, const vi& arr2, const int target) {
    return sol2(TreeFromLevelOrder(arr1), TreeFromLevelOrder(arr2), target);
}

int sol3(TreeNode* root1, TreeNode* root2, const int target) {
    unordered_set<int> values;
    stack<TreeNode*> stack;
    while (true) {
        for (; root1; root1 = root1->left) stack.push(root1);
        if (stack.empty()) break;
        values.insert(stack.top()->val);
        root1 = stack.top()->right;
        stack.pop();
    }
    while (true) {
        for (; root2; root2 = root2->right) stack.push(root2);
        if (stack.empty()) break;
        if (values.count(target - stack.top()->val)) return true;
        root2 = stack.top()->left;
        stack.pop();
    }
    return false;
}

int sol3(const vi& arr1, const vi& arr2, const int target) {
    return sol3(TreeFromLevelOrder(arr1), TreeFromLevelOrder(arr2), target);
}

int main() { TimeMeasure _; __x();
    cout << sol({2,1,4}, {1,0,3}, 5) << endl; // 1
    cout << sol({0,-10,10}, {5,1,7,0,2}, 18) << endl; // 0
    cout << sol({0,-10,10}, {5,1,7,0,2}, 17) << endl; // 1
    cout << endl;
    cout << sol2({2,1,4}, {1,0,3}, 5) << endl; // 1
    cout << sol2({0,-10,10}, {5,1,7,0,2}, 18) << endl; // 0
    cout << sol2({0,-10,10}, {5,1,7,0,2}, 17) << endl; // 1
    cout << endl;
    cout << sol3({2,1,4}, {1,0,3}, 5) << endl; // 1
    cout << sol3({0,-10,10}, {5,1,7,0,2}, 18) << endl; // 0
    cout << sol3({0,-10,10}, {5,1,7,0,2}, 17) << endl; // 1
}
