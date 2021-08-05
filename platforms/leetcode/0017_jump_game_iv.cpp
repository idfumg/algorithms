#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] == arr[n - 1]) return 1;
    unordered_map<int, vi> idx;
    for (int i = 0; i < n; ++i) {
        if (i > 0 and arr[i] == arr[i - 1]) {
            while (i < n and arr[i] == arr[i - 1]) ++i;
            if (i - 1 < n) idx[arr[i - 1]].push_back(i - 1);
            if (i < n) idx[arr[i]].push_back(i);
        }
        else {
            idx[arr[i]].push_back(i);
        }
    }
    deque<int> q;
    q.push_back(0);
    vb visited(n);
    vi dist(n, INF);
    dist[0] = 0;
    while (not q.empty()) {
        const int at = q.front(); q.pop_front();
        visited[at] = true;
        for (int adj : idx[arr[at]]) {
            if (not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }
        for (int adj : {at - 1, at + 1}) {
            if (adj < 0 or adj >= n) {
                continue;
            }
            else if (not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }

    }
    return dist[n - 1];
}

int main() { TimeMeasure _; __x();
    cout << tab({100,-23,-23,404,100,23,23,23,3,404}) << endl; // 3
    cout << tab({7}) << endl; // 0
    cout << tab({7,6,9,6,9,6,9,7}) << endl; // 1
    cout << tab({6,1,9}) << endl; // 2
    cout << tab({11,22,7,7,7,7,7,7,7,22,13}) << endl; // 3
    cout << tab({51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63}) << endl; // 4
    cout << tab({7,7,2,1,7,7,7,3,4,1}) << endl; // 3
}
