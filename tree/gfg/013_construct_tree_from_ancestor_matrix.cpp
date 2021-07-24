#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* construct(vvi arr) {
    priority_queue<pi, vpi, greater<pi>> pq;
    int n = arr.size();
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(i);
        pq.push({reduce(arr[i].begin(), arr[i].end(), 0), i});
    }
    vb visited(n);
    Node* root = nullptr;
    while (not pq.empty()) {
        const auto [childrenCount, at] = pq.top(); pq.pop();
        root = nodes[at];
        if (childrenCount == 0) continue;
        for (int adj = 0; adj < n; ++adj) {
            if (not visited[adj] and arr[at][adj]) {
                if (not root->left) root->left = nodes[adj];
                else if (not root->right) root->right = nodes[adj];
                visited[adj] = true;
            }
        }
    }
    return root;
}

int main() { TimeMeasure _; __x();
    vvi arr =
        {{ 0, 0, 0, 0, 0, 0 },
         { 1, 0, 0, 0, 1, 0 },
         { 0, 0, 0, 1, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 1, 1, 1, 1, 1, 0 }};

    Node* root = construct(arr); // 0 1 4 5 3 2
    cout << root << endl;
}
