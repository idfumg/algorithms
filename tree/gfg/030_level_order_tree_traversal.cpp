#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void levelorder(Node* root) {
    deque<Node*> q;
    q.push_back(root);
    while (not q.empty()) {
        Node* at = q.front(); q.pop_front();
        cout << at->value << ' ';
        if (at->left) q.push_back(at->left);
        if (at->right) q.push_back(at->right);
    }
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelorder(root); // 1 2 3 4 5
}
