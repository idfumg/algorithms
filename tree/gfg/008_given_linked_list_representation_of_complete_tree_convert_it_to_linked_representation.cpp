#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(Node* head) {
    Node* root = new Node(head->value);
    head = head->right;
    deque<Node*> q;
    q.push_back(root);
    while (not q.empty() and head) {
        Node* node = q.front(); q.pop_front();

        Node* left = node->left = new Node(head->value);
        q.push_back(left);
        head = head->right;

        if (head) {
            Node* right = node->right = new Node(head->value);
            q.push_back(right);
            head = head->right;
        }
    }
    return root;
}

void ConstructCompleteBinaryTree(Node* head) {
    Node* root = construct(head);
    cout << root << endl;
}

int main() { TimeMeasure _; __x();
    vi levelOrder = {10, 12, 15, 25, 30, 36};
    Node* head = make_list(levelOrder);
    ConstructCompleteBinaryTree(head); // 25 12 30 10 36 15
}
