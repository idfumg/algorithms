#include "../../template.hpp"

int dfs(const vi& arr, const int from) {
    const int n = arr.size();
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    while (not q.empty()) {
        const int at = q.front(); q.pop_front();
        if (arr[at] == 0) return true;
        visited[at] = true;
        for (int adj : {at - arr[at], at + arr[at]}) {
            if (adj < 0 or adj >= n) continue;
            if (not visited[adj]) {
                q.push_back(adj);
            }
        }
    }
    return false;
}

int main() { TimeMeasure _; __x();
    cout << dfs({4,2,3,0,3,1,2}, 5) << endl; // 1
    cout << dfs({4,2,3,0,3,1,2}, 0) << endl; // 1
    cout << dfs({3,0,2,1,2}, 2) << endl; // 0
}
