#include "../../template.hpp"

int bfs(vi elems, vi& dist, int from) {
    int n = elems.size();
    int ans = 0;
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    dist[from] = 0;
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;
        int adj = elems[at];
        if (not visited[adj]) {
            dist[adj] = dist[at] + 1;
            ans = max(ans, dist[adj]);
            q.push_back(adj);
        }
    }
    return ans;
}

int sol(vi elems) {
    int ans = 0;
    int n = elems.size();
    vi dist(n, INF);
    for (int i = 0; i < elems.size(); ++i) {
        if (dist[i] != INF) ans = max(ans, dist[i] + 1);
        else ans = max(ans, bfs(elems, dist, i) + 1);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({5,4,0,3,1,6,2}) << endl; // 4
    cout << sol({0,1,2}) << endl; // 1
    cout << sol({0,2,1}) << endl; // 2
}
