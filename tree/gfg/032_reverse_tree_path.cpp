#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void preorder(Node* root, int target, vector<Node*>& path) {
    if (not root) return;
    path.push_back(root);
    if (path.back()->value == target) {
        for (int i = 0, j = path.size() - 1; i <= j; ++i, --j) {
            swap(path[i]->value, path[j]->value);
        }
    }
    preorder(root->left, target, path);
    preorder(root->right, target, path);
}

void reverseTreePath(Node* root, int target) {
    vector<Node*> path;
    preorder(root, target, path);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(7);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

/*
     7
   /   \
  6     5
 / \   / \
4   3 2   1
*/

    cout << root << endl; // 4 6 3 7 2 5 1
    reverseTreePath(root, 4);
    cout << root << endl; // 7 6 3 4 2 5 1
}
