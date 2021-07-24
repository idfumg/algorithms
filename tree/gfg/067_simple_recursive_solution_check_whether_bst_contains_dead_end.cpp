#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

bool hasDeadEnd(Node* root, int low, int high) {
    if (not root) return false;
    if (abs(high - low) <= 2) return true;
    return hasDeadEnd(root->left, low, root->value) or hasDeadEnd(root->right, root->value, high);
}

bool hasDeadEnd(Node* root) {
    return hasDeadEnd(root, 0, +INF);
}

int main() { TimeMeasure _; __x();
    {
        /*
               8
             /   \
           5      9
         /   \
        2     7
       /
      1
        */
        Node* root = nullptr;
        for (int value : {8, 5, 2, 3, 7, 1, 4}) {
            root = insert(root, value);
        }
        cout << hasDeadEnd(root) << endl; // 1
    }
    {
        /*
              8
            /   \
           7     10
         /      /   \
        2      9     13
        */
        Node* root = nullptr;
        for (int value : {8, 7, 2, 10, 9, 13}) {
            root = insert(root, value);
        }
        cout << hasDeadEnd(root) << endl; // 1
    }
}
