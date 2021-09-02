#include "../../template.hpp"

int dfs(const vvi& graph, vb& visited, const int to, const int at) {
    if (at == to) return 1;
    visited[at] = true;
    for (const int adj : graph[at]) {
        if (not visited[adj]) {
            if (dfs(graph, visited, to, adj)) {
                return 1;
            }
        }
    }
    return 0;
}

int sol(const vvi& edges, const int n, const int from, const int to) {
    vvi graph(n);
    for (const vi& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vb visited(n);
    return dfs(graph, visited, to, from);
}

int main() { TimeMeasure _; __x();
    cout << sol({{0,1},{1,2},{2,0}}, 3, 0, 2) << endl; // 1
    cout << sol({{0,1},{0,2},{3,5},{5,4},{4,3}}, 6, 0, 5) << endl; // 0
}
