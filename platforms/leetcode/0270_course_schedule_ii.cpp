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

vi KhanTopo(const vvi& graph) {
    const int n = graph.size();
    vi indegree(n);
    for (int at = 0; at < n; ++at) {
        for (const int adj : graph[at]) {
            ++indegree[adj];
        }
    }
    deque<int> q;
    for (int at = 0; at < n; ++at) {
        if (indegree[at] == 0) {
            q.push_back(at);
        }
    }
    vi ordering;
    while (not q.empty()) {
        const int at = q.front(); q.pop_front();
        ordering.push_back(at);
        for (const int adj : graph[at]) {
            if (--indegree[adj] == 0) {
                q.push_back(adj);
            }
        }
    }
    return ordering;
}

vi sol(const int n, const vvi& arr) {
    vvi graph(n);
    for (int i = 0; i < arr.size(); ++i) {
        graph[arr[i][1]].push_back(arr[i][0]);
    }
    if (DetectCycle(graph)) {
        return {};
    }
    return KhanTopo(graph);
}

int main() { TimeMeasure _; __x();
    cout << sol(2, {{1,0}}) << endl; // [0,1]
    cout << sol(2, {{1,0},{0,1}}) << endl; // []
    cout << sol(4, {{1,0},{2,0},{3,1},{3,2}}) << endl; // [0,2,1,3]
}
