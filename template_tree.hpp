#pragma once

#include <bits/stdc++.h>

struct Node {
    int value = 1e9 + 7;
    int val = 1e9 + 7;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* next = nullptr;
    Node* parent = nullptr;
    std::vector<Node*> children = {};
    Node(const int value) : value(value), val(value), left(nullptr), right(nullptr), next(nullptr) {}
    Node(const int value, Node* left, Node* right) : value(value), left(left), right(right), next(right) {}
};

using TreeNode = Node;
using ListNode = Node;

void print_inorder(Node* root) {
    if (not root) return;
    print_inorder(root->left);
    std::cout << root->value << ' ';
    print_inorder(root->right);
}

void print_preorder(Node* root) {
    if (not root) return;
    std::cout << root->value << ' ';
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_postorder(Node* root) {
    if (not root) return;
    print_postorder(root->left);
    print_postorder(root->right);
    std::cout << root->value << ' ';
}

Node* find_tree_node(Node* root, const int val) {
    if (not root) return nullptr;
    if (root->val == val) {
        return root;
    }
    Node* left = find_tree_node(root->left, val);
    if (left) return left;
    return find_tree_node(root->right, val);
}

TreeNode* TreeFromLevelOrder(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    std::deque<TreeNode*> q;
    q.push_back(root);
    int idx = 1;
    int n = arr.size();
    while (not q.empty()) {
        TreeNode* at = q.front();
        q.pop_front();
        if (idx < n) {
            at->left = (arr[idx] == -static_cast<int>(1e9 + 7)) ? nullptr : (new TreeNode(arr[idx]));
            ++idx;
            if (at->left) {
                q.push_back(at->left);
                at->left->parent = at;
            }
        }
        if (idx < n) {
            at->right = (arr[idx] == -static_cast<int>(1e9 + 7)) ? nullptr : (new TreeNode(arr[idx]));
            ++idx;
            if (at->right) {
                q.push_back(at->right);
                at->right->parent = at;
            }
        }
    }
    return root;
}

Node* make_list(const std::vector<int>& arr) {
    Node* head = nullptr;
    Node* current = nullptr;
    for (int value : arr) {
        if (head == nullptr) {
            current = head = new Node(value);
        } else {
            current->right = current->next = new Node(value);
            current = current->right;
        }
    }
    return head;
}

void print_list(Node* head) {
    for (Node* curr = head; curr; curr = curr->right) std::cout << curr->value << ' ';
    std::cout << std::endl;
}

void print_list2(Node* head) {
    for (Node* curr = head; curr; curr = curr->next) std::cout << curr->value << ' ';
    std::cout << std::endl;
}
