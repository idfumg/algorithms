#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

std::optional<int> inorderSuccesor(Node* root, Node* node, Node*& prev) {
    if (not root) return std::nullopt;
    if (const auto ans = inorderSuccesor(root->left, node, prev)) return ans;
    if (prev and prev == node) return root->value;
    prev = root;
    return inorderSuccesor(root->right, node, prev);
}

void inorderSuccesor(Node* root, Node* node) {
    Node* prev = nullptr;
    const auto ans = inorderSuccesor(root, node, prev);
    cout << ans.value_or(-1) << endl;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    inorderSuccesor(root, root->right); // 6
    inorderSuccesor(root, root->left->left); // 2
    inorderSuccesor(root, root->right->right); // -1
    inorderSuccesor(root, root->left->right); // 1
}
