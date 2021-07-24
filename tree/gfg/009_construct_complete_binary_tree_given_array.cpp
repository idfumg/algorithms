#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void ConstructCompleteBinaryTree(vi level) {
    int idx = 0;
    deque<Node*> q;
    Node* root = new Node(level[idx++]);
    q.push_back(root);
    while (not q.empty() and idx < level.size()) {
        Node* node = q.front(); q.pop_front();
        node->left = new Node(level[idx++]);
        q.push_back(node->left);
        if (idx < level.size()) {
            node->right = new Node(level[idx++]);
            q.push_back(node->right);
        }
    }
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi level = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    ConstructCompleteBinaryTree(level); // 6 4 6 2 5 1 6 3 6
}
