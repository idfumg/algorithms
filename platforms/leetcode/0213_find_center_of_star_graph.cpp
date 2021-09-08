#include "../../template.hpp"

int sol(const vvi& arr) {
    const int n = 100001;
    vvi graph(n);
    for (const auto& edge : arr) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vi degree(n);
    for (int at = 0; at < n; ++at) {
        degree[at] = graph[at].size();
    }
    deque<int> q;
    for (int at = 0; at < n; ++at) {
        if (degree[at] == 1) {
            q.push_back(at);
        }
    }
    if (q.empty()) return 0;
    while (q.size() > 1) {
        const int at = q.front(); q.pop_front();
        for (const int adj : graph[at]) {
            if (--degree[adj] == 1) {
                q.push_back(adj);
            }
        }
    }
    return q.front();
}

int main() { TimeMeasure _; //__x();
    cout << sol({{1,2},{2,3},{4,2}}) << endl; // 2
    cout << sol({{1,2},{5,1},{1,3},{1,4}}) << endl; // 1
}
