#include "../../template.hpp"

static const vvi directions = {
    {0,1},{0,-1},{1,0},{-1,0},
};

void dfs(const vvi& arr, vvb& visited, const int total, const vi& to, int& ans, const vi& at, const int current) {
    const int m = arr.size();
    const int n = arr[0].size();
    if (at == to) {
        if (total == current - 1) {
            ++ans;
        }
    }
    visited[at[0]][at[1]] = 1;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < m and j < n and (arr[i][j] == 0 or arr[i][j] == 2) and not visited[i][j]) {
            dfs(arr, visited, total, to, ans, {i, j}, current + 1);
        }
    }
    visited[at[0]][at[1]] = 0;
}

int sol(const vvi& arr) {
    const int m = arr.size();
    const int n = arr[0].size();
    vvb visited(m, vb(n));
    vi from = {-1, -1};
    vi to = {-1, -1};
    int total = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) from = {i, j};
            else if (arr[i][j] == 2) to = {i, j};
            else if (arr[i][j] == 0) ++total;
        }
    }
    int ans = 0;
    dfs(arr, visited, total, to, ans, from, 0);
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({{1,0,0,0},{0,0,0,0},{0,0,2,-1}}) << endl; // 2
    cout << sol({{1,0,0,0},{0,0,0,0},{0,0,0,2}}) << endl; // 4
    cout << sol({{0,1},{2,0}}) << endl; // 0
}
