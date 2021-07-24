#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

Node* MergeTrees(Node* root1, Node* root2) {
    vi arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    Node* root = nullptr;
    int i = 0, j = 0;
    while (i < arr1.size() and j < arr2.size()) {
        if (arr1[i] < arr2[j]) root = insert(root, arr1[i++]);
        else root = insert(root, arr2[j++]);
    }
    while (i < arr1.size()) root = insert(root, arr1[i++]);
    while (j < arr2.size()) root = insert(root, arr2[j++]);
    return root;
}

int main() { TimeMeasure _; __x();
    /*
     100
    /  \
  50   300
 /  \
20  70
*/
    Node* root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

/*
    80
   /  \
  40  120
*/
    Node* root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node* mergedTree = MergeTrees(root1, root2);
    cout << mergedTree << endl; // 20 40 50 70 80 100 120 300
}
