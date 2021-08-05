#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void AddEdge(vvi& graph, int from, int to) {
    --from; --to;
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int EdgesToRemove(vvi graph, int& ans, int at, int parent = -1) {
    int count = 1;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        int remain = EdgesToRemove(graph, ans, adj, at);
        if (remain & 1) {
            count += remain;
        }
        else {
            ans += 1;
        }
    }
    return count;
}

int EdgesToRemove(vvi graph, int at) {
    int ans = 0;
    EdgesToRemove(graph, ans, at, -1);
    return ans;
}

int main() { TimeMeasure _; __x();
    int n = 10;
    vvi graph(n);

    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 6);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 3, 4);
    AddEdge(graph, 6, 8);
    AddEdge(graph, 2, 7);
    AddEdge(graph, 2, 5);
    AddEdge(graph, 4, 9);
    AddEdge(graph, 4, 10);

    cout << EdgesToRemove(graph, 0) << endl; // 2
}
