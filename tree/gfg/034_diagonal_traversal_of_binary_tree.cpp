#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void preorder(Node* root, map<int, vi>& tab, int diagonal) {
    if (not root) return;
    tab[diagonal].push_back(root->value);
    preorder(root->left, tab, diagonal + 1);
    preorder(root->right, tab, diagonal);
}

void DiagonalPrint(Node* root) {
    map<int, vi> tab;
    preorder(root, tab, 0);
    for (const auto& [diagonal, nodes] : tab) {
        cout << nodes << endl;
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    DiagonalPrint(root);
/*
8 10 14
3 6 7 13
1 4
*/
}
