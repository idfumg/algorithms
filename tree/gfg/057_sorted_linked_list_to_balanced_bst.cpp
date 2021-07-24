#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_preorder(root); return os; }

Node* find_mid(Node* head, Node* tail) {
    if (head == tail) return nullptr;
    Node* curr = head;
    while (curr and curr->right and curr->right != tail) {
        head = head->right;
        curr = curr->right;
        if (curr) curr = curr->right;
    }
    return head;
}

Node* create_bst(Node* head, Node* tail) {
    if (head == tail) return nullptr;
    Node* mid = find_mid(head, tail);
    if (mid == nullptr) return nullptr;
    Node* root = new Node(mid->value);
    root->left = create_bst(head, mid);
    root->right = create_bst(mid->right, tail);
    return root;
}

Node* create_bst(Node* head) {
    return create_bst(head, nullptr);
}

int main() { TimeMeasure _; __x();
    Node* head = make_list({1, 2, 3, 4, 5, 6, 7});
    print_list(head); cout << endl; // 1 2 3 4 5 6 7

    Node* root = create_bst(head);
    cout << root << endl; // 4 2 1 3 6 5 7

    return 0;
}
