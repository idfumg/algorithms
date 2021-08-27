#include "../../template.hpp"

static const vvi directions = {
    {0,1}, {0,-1}, {1,0}, {-1,0},
};

static bool is_valid_coords(const vector<vector<char>>& grid, const int i, const int j) noexcept {
    return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
}

static int dfs(const vector<vector<char>>& grid, vvb& visited, const string& s, int& idx, const vi& at) noexcept {
    if (s[idx] != grid[at[0]][at[1]]) return 0;
    if (idx == s.size() - 1) return 1;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (is_valid_coords(grid, i, j) and not visited[i][j] and s[idx + 1] == grid[i][j]) {
            ++idx;
            visited[i][j] = true;
            if (dfs(grid, visited, s, idx, {i, j})) {
                return 1;
            }
            visited[i][j] = false;
            --idx;
        }
    }
    return 0;
}

static int sol(const vector<vector<char>>& grid, const string& s) noexcept {
    const int m = grid.size();
    const int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == s[0]) {
                vvb visited(m, vb(n));
                int idx = 0;
                visited[i][j] = true;
                if (dfs(grid, visited, s, idx, {i, j})) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED") << endl; // 1
    cout << sol({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "SEE") << endl; // 1
    cout << sol({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCB") << endl; // 0
    cout << sol({{'a'}}, "a") << endl; // 1
}
