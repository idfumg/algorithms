#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

Node* construct(string s, int& idx) {
    if (idx >= s.size()) return nullptr;
    Node* root = new Node(s[idx++] - '0');
    if (idx < s.size() and s[idx] == '?') {
        root->left = construct(s, ++idx);
        root->right = construct(s, ++idx);
    }
    else if (idx < s.size() and s[idx] == ':') {
        root->right = construct(s, ++idx);
    }
    return root;
}

void construct(string s) {
    int idx = 0;
    Node* root = construct(s, idx);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    construct("1?2:3"); // 1 2 3
    construct("1?2?3:4:5"); // 1 2 3 4 5
}
