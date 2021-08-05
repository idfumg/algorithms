#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

vi getLevel(vi in, vi level, int i, int j) {
    unordered_set<int> nodes;
    for (; i <= j; ++i) {
        nodes.insert(in[i]);
    }
    vi ans;
    for (int value : level) {
        if (nodes.count(value)) {
            ans.push_back(value);
        }
    }
    return ans;
}

Node* construct(vi in, vi level, int i, int j) {
    if (i > j or level.empty()) return nullptr;
    int rootValue = level[0];
    int k = i;
    while (k <= j and in[k] != rootValue) ++k;
    vi leftLevel = getLevel(in, level, i, k - 1);
    vi rightLevel = getLevel(in, level, k + 1, j);
    Node* root = new Node(rootValue);
    root->left = construct(in, leftLevel, i, k - 1);
    root->right = construct(in, rightLevel, k + 1, j);
    return root;
}

void Build(vi in, vi level) {
    Node* root = construct(in, level, 0, in.size() - 1);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = {4, 8, 10, 12, 14, 20, 22};
    vi levelorder = {20, 8, 22, 4, 12, 10, 14};
    Build(inorder, levelorder); // 4 8 10 12 14 20 22
}
