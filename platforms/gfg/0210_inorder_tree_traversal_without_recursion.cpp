#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void InorderIter(Node* node) {
    vector<Node*> stack;
    for (; node; node = node->left) stack.push_back(node);
    while (not stack.empty()) {
        Node* node = stack.back(); stack.pop_back();
        cout << node->value << ' ';
        node = node->right;
        for (; node; node = node->left) stack.push_back(node);
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << root << endl; // 4 2 5 1 3
    InorderIter(root); // 4 2 5 1 3
}
