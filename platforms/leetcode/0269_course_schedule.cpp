#include "../../template.hpp"

bool dfs(const vvi& graph, vi& visited, const int at) {
    visited[at] = 1;
    for (const int adj : graph[at]) {
        if (visited[adj] == 2) continue;
        if (visited[adj] == 1) return true;
        if (dfs(graph, visited, adj)) return true;
    }
    visited[at] = 2;
    return false;
}

bool DetectCycle(const vvi& graph) {
    const int n = graph.size();
    vi visited(n, -1);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == -1) {
            if (dfs(graph, visited, i)) {
                return true;
            }
        }
    }
    return false;
}

bool sol(const int n, const vvi& arr) {
    vvi graph(n);
    for (int i = 0; i < arr.size(); ++i) {
        graph[arr[i][1]].push_back(arr[i][0]);
    }
    return not DetectCycle(graph);
}

int main() { TimeMeasure _; __x();
    cout << sol(2, {{1,0}}) << endl; // 1
    cout << sol(2, {{1,0},{0,1}}) << endl; // 0
}
