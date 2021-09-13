#include "../../template.hpp"

static const vvi directions = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(const vvi& grid, vvb& visited, const vi& at, int& count, int& ans) {
    ++count;
    ans = max(ans, count);
    visited[at[0]][at[1]] = 1;
    for (const vi& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and not visited[i][j] and grid[i][j] == 1) {
            dfs(grid, visited, {i, j}, count, ans);
        }
    }
}

int sol(const vvi& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    vvb visited(m, vb(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (not visited[i][j] and grid[i][j] == 1) {
                int count = 0;
                dfs(grid, visited, {i, j}, count, ans);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    const vvi grid1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    const vvi grid2 = {{0,0,0,0,0,0,0,0}};

    cout << sol(grid1) << endl; // 6
    cout << sol(grid2) << endl; // 0
}
