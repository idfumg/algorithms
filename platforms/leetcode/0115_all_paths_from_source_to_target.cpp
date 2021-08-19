#include "../../template.hpp"

vvi tab(const vvi& graph) {
    const int n = graph.size();
    const int from = 0;
    const int to = n - 1;
    deque<vi> q;
    q.push_back({from});
    vvi ans;
    while (not q.empty()) {
        const vi currpath = q.front(); q.pop_front();
        const int at = currpath.back();
        for (const int adj : graph[at]) {
            vi path = currpath;
            path.push_back(adj);
            if (adj == to) {
                ans.push_back(path);
            }
            else {
                q.push_back(path);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({{1,2},{3},{3},{}}) << endl; // [[0,1,3],[0,2,3]]
    cout << tab({{4,3,1},{3,2,4},{3},{4},{}}) << endl; // [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    cout << tab({{1},{}}) << endl; // [[0,1]]
    cout << tab({{1,2,3},{2},{3},{}}) << endl; // [[0,1,2,3],[0,2,3],[0,3]]
    cout << tab({{1,3},{2},{3},{}}) << endl; // [[0,1,2,3],[0,3]]
}
