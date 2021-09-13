#include "../../template.hpp"

void inorder(Node* root, Node*& head, Node*& prev) {
    if (not root) return;
    inorder(root->left, head, prev);
    if (not head) {
        head = root;
        prev = root;
    }
    else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    inorder(root->right, head, prev);
}

Node* sol(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;
    inorder(root, head, prev);
    // prev->right = head;
    // head->left = prev;
    return head;
}

Node* sol(const vi& arr) {
    return sol(TreeFromLevelOrder(arr));
}

ostream& operator<<(ostream& os, Node* root) {
    print_list(root); return os;
}

int main() { TimeMeasure _; __x();
    cout << sol({4,2,5,1,3}) << endl; // 1,2,3,4,5
    cout << sol({2,1,3}) << endl; // 1,2,3
    cout << sol({}) << endl; // []
    cout << sol({1}) << endl; // [1]
}
