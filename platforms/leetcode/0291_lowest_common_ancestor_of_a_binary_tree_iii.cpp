#include "../../template.hpp"

Node* sol(Node* p, Node * q) {
    Node* a = p;
    Node* b = q;
    while (a != b) {
        a = a == nullptr ? q : a->parent;
        b = b == nullptr ? p : b->parent;
    }
    return a;
}

int get_depth(Node* root) {
    int ans = 0;
    for (; root; root = root->parent) {
        ++ans;
    }
    return ans;
}

Node* sol2(Node* p, Node* q) {
    if (not p or not q) return nullptr;
    int p_depth = get_depth(p);
    int q_depth = get_depth(q);
    while (p_depth > q_depth) {
        --p_depth;
        p = p->parent;
    }
    while (q_depth > p_depth) {
        --q_depth;
        q = q->parent;
    }
    while (p != q) {
        p = p->parent;
        q = q->parent;
    }
    return p;
}

int sol2(const vi& arr, const int a, const int b) {
    Node* root = TreeFromLevelOrder(arr);
    return sol2(find_tree_node(root, a), find_tree_node(root, b))->val;
}

int sol(const vi& arr, const int a, const int b) {
    Node* root = TreeFromLevelOrder(arr);
    return sol(find_tree_node(root, a), find_tree_node(root, b))->val;
}

int main() { TimeMeasure _; __x();
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 1) << endl; // 3
    cout << sol({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 4) << endl; // 5
    cout << sol({1,2}, 1, 2) << endl; // 1
    cout << endl;
    cout << sol2({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 1) << endl; // 3
    cout << sol2({3,5,1,6,2,0,8,-INF,-INF,7,4}, 5, 4) << endl; // 5
    cout << sol2({1,2}, 1, 2) << endl; // 1
}
