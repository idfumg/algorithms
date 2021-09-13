#include "../../template.hpp"

static const vvi directions = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(const vvi& grid, vvb& visited, const vi& at) {
    visited[at[0]][at[1]] = true;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and not visited[i][j] and grid[i][j] == 1) {
            dfs(grid, visited, {i, j});
        }
    }
}

void dfs(const vvi& grid, vvb& visited1, vvb& visited2, const vi& at, bool& is_valid) {
    if (not visited1[at[0]][at[1]]) {
        is_valid = false;
    }
    visited2[at[0]][at[1]] = true;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and not visited2[i][j] and grid[i][j] == 1) {
            dfs(grid, visited1, visited2, {i, j}, is_valid);
        }
    }
}

int sol(const vvi& grid1, const vvi& grid2) {
    const int m = grid1.size();
    const int n = grid1[0].size();
    vvb visited(m, vb(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (not visited[i][j] and grid1[i][j] == 1) {
                dfs(grid1, visited, {i, j});
            }
        }
    }
    vvb visited2(m, vb(n));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (not visited2[i][j] and grid2[i][j] == 1 and visited[i][j]) {
                bool is_valid = true;
                dfs(grid2, visited, visited2, {i, j}, is_valid);
                if (is_valid) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    const vvi grid11 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    const vvi grid12 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    const vvi grid21 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    const vvi grid22 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};

    cout << sol(grid11, grid12) << endl; // 3
    cout << sol(grid21, grid22) << endl; // 2
}
