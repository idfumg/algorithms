#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

int preorder(Node* root, int level) {
    if (not root) return -INF;
    if (not root->left and not root->right) return level & 1 ? level : -INF;
    return max(preorder(root->left, level + 1), preorder(root->right, level + 1));
}

int DeepestOddLevelDepth(Node* root) {
    return preorder(root, 1);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(10);
        root->left = new Node(28);
        root->right = new Node(13);
        root->right->left = new Node(14);
        root->right->right = new Node(15);
        root->right->right->left = new Node(23);
        root->right->right->right = new Node(24);

        cout << DeepestOddLevelDepth(root) << endl; // 3
    }
    {
        Node* root = new Node(5);
        root->left = new Node(10);
        root->left->left = new Node(3);
        root->left->right = new Node(4);
        root->left->right->left = new Node(44);
        root->left->right->left->right = new Node(12);

        root->right = new Node(2);
        root->right->right = new Node(15);
        root->right->right->left = new Node(9);
        root->right->right->right = new Node(8);

        cout << DeepestOddLevelDepth(root) << endl; // 5
    }
}
