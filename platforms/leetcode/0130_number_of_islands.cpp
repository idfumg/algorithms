#include "../../template.hpp"

static const vvi directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

void dfs(const vector<vector<string>>& grid, vvb& visited, const vi& at) {
    visited[at[0]][at[1]] = true;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size()) {
            if (not visited[i][j] and grid[i][j] == "1") {
                dfs(grid, visited, {i, j});
            }
        }
    }
}

int rec(const vector<vector<string>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vvb visited(m + 1, vb(n + 1));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == "1" and not visited[i][j]) {
                ++ans;
                dfs(grid, visited, {i, j});
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    const vector<vector<string>> grid1 = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    const vector<vector<string>> grid2 = {
        {"1","1","0","0","0"},
        {"1","1","0","0","0"},
        {"0","0","1","0","0"},
        {"0","0","0","1","1"}
    };
    const vector<vector<string>> grid3 = {
        {"1"},
        {"0"},
        {"1"},
        {"0"},
        {"1"},
        {"1"}
    };
    cout << rec(grid1) << endl; // 1
    cout << rec(grid2) << endl; // 3
    cout << rec(grid3) << endl; // 3
}
