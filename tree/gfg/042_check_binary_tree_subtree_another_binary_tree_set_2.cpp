#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

bool AreEqual(Node* T, Node* S) {
    if (not T and not S) return true;
    if (not T or not S) return false;
    return T->value == S->value and AreEqual(T->left, S->left) and AreEqual(T->right, S->right);
}

bool IsSubtree(Node* T, Node* S) {
    if (not S) return false;
    return AreEqual(T, S) or IsSubtree(T, S->left) or IsSubtree(T, S->right);
}

int main() { TimeMeasure _; __x();
    {
        Node* T = new Node(1);
        T->left = new Node(2);
        T->right = new Node(4);
        T->left->left = new Node(3);
        T->right->right = new Node(5);

        Node* S = new Node(1);
        S->left = new Node(2);
        S->left->left = new Node(3);
        S->right = new Node(4);

        cout << IsSubtree(T, S) << endl; // 0
    }
    {
        Node* T = new Node(6);
        T->left = new Node(1);
        T->left->right = new Node(3);
        T->right = new Node(2);

        Node* S = new Node(8);
        S->left = new Node(6);
        S->left->left = new Node(1);
        S->left->left->right = new Node(3);
        S->left->right = new Node(2);
        S->right = new Node(5);
        S->right->right = new Node(7);

        cout << IsSubtree(T, S) << endl; // 1
    }
}
