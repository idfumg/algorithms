#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

void height(Node* root, vi& path, vi& curr) {
    if (not root) return;
    curr.push_back(root->value);
    if (curr.size() > path.size()) path = curr;
    height(root->left, path, curr);
    height(root->right, path, curr);
    curr.pop_back();
}

void diameter(Node* root, vi& path) {
    if (not root) return;

    vi left, right, curr;
    height(root->left, left, curr);
    height(root->right, right, curr);

    if (left.size() + 1 + right.size() > path.size()) {
        path.assign(left.rbegin(), left.rend());
        path.push_back(root->value);
        copy(right.begin(), right.end(), back_inserter(path));
    }

    diameter(root->left, path);
    diameter(root->right, path);
}

void Diameter(Node* root) {
    vi path;
    diameter(root, path);
    debugn(path);
}

int main() { TimeMeasure _; __x();
    {
        //           1
        //         /   \
        //        2     3
        //      /   \
        //     4     5
        //      \   / \
        //       8 6   7
        //      /
        //     9
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->left->right->left = new Node(6);
        root->left->right->right = new Node(7);
        root->left->left->right = new Node(8);
        root->left->left->right->left = new Node(9);

        Diameter(root); // 9 8 4 2 1 3
    }
    {
        Node* root = new Node(1);
        root->right = new Node(2);
        root->left = new Node(3);

        root->left->right = new Node(4);
        root->left->right->right = new Node(5);
        root->left->right->left = new Node(6);
        root->left->right->right->right = new Node(7);
        root->left->right->right->right->left = new Node(8);

        root->left->left = new Node(9);
        root->left->left->right = new Node(10);
        root->left->left->right->left = new Node(11);
        root->left->left->right->left->right = new Node(12);

        root->left->left->left = new Node(13);

        Diameter(root); //
    }
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right = new Node(3);

        Diameter(root); // 4 2 1 3 or 5 2 1 3
    }
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right = new Node(3);
        root->right->right = new Node(6);

        Diameter(root); // 4 2 1 3 6 or 5 2 1 3 6
    }
}
