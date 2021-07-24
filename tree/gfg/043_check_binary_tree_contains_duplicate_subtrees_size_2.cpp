#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

string preorder(Node* root) {
    if (not root) return "";
    return to_string(root->value) + preorder(root->left) + preorder(root->right);
}

bool preorder(Node* root, unordered_set<string>& subtrees) {
    if (not root) return false;

    const string tree = preorder(root);
    if (subtrees.count(tree)) return true;
    else if (tree.size() > 1) subtrees.insert(tree);

    return preorder(root->left, subtrees) or preorder(root->right, subtrees);
}

bool HasDuplicateSubTree(Node* root) {
    unordered_set<string> subtrees;
    return preorder(root, subtrees);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(2);
    root->right->right->right = new Node(3);
    root->right->right->left= new Node(5);

    cout << HasDuplicateSubTree(root) << endl; // 1
}
