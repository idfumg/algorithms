#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->value);
    inorder(root->right, in);
}

void inorder(Node* root, vi& in, int& idx) {
    if (not root) return;
    inorder(root->left, in, idx);

    int n = in.size();
    if (root->value == in[0] or idx != 0) {
        root->value = in[n - 1] - in[idx++];
    }

    inorder(root->right, in, idx);
}

void transform(Node* root) {
    vi in;
    inorder(root, in);

    int n = in.size();
    for (int i = 1; i < n; ++i) {
        in[i] += in[i - 1];
    }

    int idx = 0;
    inorder(root, in, idx);
}

void inorder(Node* root, int& sum) {
    if (not root) return;
    inorder(root->right, sum);
    if (sum == -INF) {
        sum = root->value;
    }
    else {
        int temp = root->value;
        root->value = sum;
        sum += temp;
    }
    inorder(root->left, sum);
}

void transform2(Node* root) {
    if (not root) return;
    int sum = -INF;
    inorder(root, sum);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(11);
        root->left = new Node(2);
        root->right = new Node(29);
        root->left->left = new Node(1);
        root->left->right = new Node(7);
        root->right->left = new Node(15);
        root->right->right = new Node(40);
        root->right->right->left = new Node(35);

        cout << root << endl; // 1 2 7 11 15 29 35 40
        transform(root);
        cout << root << endl << endl; // 139 137 130 119 104 75 40 0
    }
    {
        Node* root = new Node(11);
        root->left = new Node(2);
        root->right = new Node(29);
        root->left->left = new Node(1);
        root->left->right = new Node(7);
        root->right->left = new Node(15);
        root->right->right = new Node(40);
        root->right->right->left = new Node(35);

        cout << root << endl; // 1 2 7 11 15 29 35 40
        transform2(root);
        cout << root << endl << endl; // 139 137 130 119 104 75 40 0
    }
}
