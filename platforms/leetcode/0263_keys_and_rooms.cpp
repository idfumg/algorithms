#include "../../template.hpp"

void dfs(const vvi& arr, vb& visited, unordered_set<int>& keys, const int at) {
    if (not keys.count(at)) return;
    visited[at] = true;
    for (const int key : arr[at]) {
        keys.insert(key);
    }
    for (const int key : arr[at]) {
        if (not visited[key]) {
            dfs(arr, visited, keys, key);
        }
    }
}

int sol(const vvi& arr) {
    const int n = arr.size();
    vb visited(n);
    unordered_set<int> keys = {0};
    for (int i = 0; i < n; ++i) {
        if (not visited[i] and keys.count(i)) {
            dfs(arr, visited, keys, i);
        }
    }
    return all_of(visited.begin(), visited.end(), [](const bool v){return v;});
}

int main() { TimeMeasure _; __x();
    cout << sol({{1},{2},{3},{}}) << endl; // 1
    cout << sol({{1,3},{3,0,1},{2},{0}}) << endl; // 0
}
