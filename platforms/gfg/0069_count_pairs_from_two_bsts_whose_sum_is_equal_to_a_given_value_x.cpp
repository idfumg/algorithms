#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void preorder(Node* root, unordered_set<int>& tab) {
    if (not root) return;
    tab.insert(root->value);
    preorder(root->left, tab);
    preorder(root->right, tab);
}

int CountPairs(Node* root1, Node* root2, int target) {
    unordered_set<int> tab1, tab2;
    preorder(root1, tab1);
    preorder(root2, tab2);
    int count = 0;
    for (int value : tab1) {
        int diff = target - value;
        if (tab2.count(diff)) ++count;
    }
    return count;
}

int main() { TimeMeasure _; __x();
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    cout << CountPairs(root1, root2, 16) << endl; // 3
}
