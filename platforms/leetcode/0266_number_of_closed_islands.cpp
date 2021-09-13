#include "../../template.hpp"

static const vvi directions = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(const vvi& arr, vvb& visited, const vi& at) {
    visited[at[0]][at[1]] = true;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < arr.size() and j < arr[0].size() and not visited[i][j] and arr[i][j] == 0) {
            dfs(arr, visited, {i, j});
        }
    }
}

int sol(const vvi& arr) {
    const int m = arr.size();
    const int n = arr[0].size();
    vvb visited(m, vb(n));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (arr[i][j] == 1) {
                visited[i][j] = true;
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        if (arr[0][j] == 0) {
            dfs(arr, visited, {0, j});
        }
        if (arr[m - 1][j] == 0) {
            dfs(arr, visited, {m - 1, j});
        }
    }
    for (int i = 0; i < m; ++i) {
        if (arr[i][0] == 0) {
            dfs(arr, visited, {i, 0});
        }
        if (arr[i][n - 1] == 0) {
            dfs(arr, visited, {i, n - 1});
        }
    }
    for (int j = 0; j < n; ++j) {
        visited[0][j] = true;
        visited[m - 1][j] = true;
    }
    for (int i = 0; i < m; ++i) {
        visited[i][0] = true;
        visited[i][n - 1] = true;
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (arr[i][j] == 0 and not visited[i][j]) {
                ++ans;
                dfs(arr, visited, {i, j});
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    const vvi arr1 = {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0},
    };

    const vvi arr2 = {
        {0,0,1,0,0},
        {0,1,0,1,0},
        {0,1,1,1,0},
    };

    const vvi arr3 = {
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
    };

    cout << sol(arr1) << endl; // 2
    cout << sol(arr2) << endl; // 1
    cout << sol(arr3) << endl; // 2
}
