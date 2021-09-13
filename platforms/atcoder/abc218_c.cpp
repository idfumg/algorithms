//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

vector<vector<char>> read_grid(const int n, istream& is = std::cin) {
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            is >> grid[i][j];
        }
    }
    return grid;
}

vector<vector<char>> rotate_grid(const vector<vector<char>>& grid) {
    const int n = grid.size();
    vector<vector<char>> ans(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            ans[n - j - 1][i] = grid[i][j];
        }
    }
    return ans;
}

tuple<int, int, int> find_shape(const vector<vector<char>>& grid) {
    const int n = grid.size();
    int ii = -1;
    int jj = -1;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '#') {
                if (ii == -1 and jj == -1) {
                    ii = i;
                    jj = j;
                }
                ++count;
            }
        }
    }
    return {ii, jj, count};
}

bool compare_grids(const vector<vector<char>>& grid1, const vector<vector<char>>& grid2) {
    const int n = grid1.size();
    const auto [x1, y1, count1] = find_shape(grid1);
    const auto [x2, y2, count2] = find_shape(grid2);
    if (x1 == -1 or y1 == -1 or x2 == -1 or y2 == -1 or count1 != count2) {
        return false;
    }
    const int ioffset = x2 - x1;
    const int joffset = y2 - y1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            const int ii = i + ioffset;
            const int jj = j + joffset;
            if (ii >= 0 and jj >= 0 and ii < n and jj < n) {
                if (grid1[i][j] != grid2[ii][jj]) {
                    return false;
                }
            }
            else {
                if (grid1[i][j] == '#') {
                    return false;
                }
            }
        }
    }
    return true;
}

void sol(istream& is = std::cin) {
    int n; is >> n;

    auto grid1 = read_grid(n, is);
    const auto grid2 = read_grid(n, is);

    for (int _ = 0; _ < 4; ++_) {
        if (compare_grids(grid1, grid2)) {
            cout << "Yes";
            return;
        }
        grid1 = rotate_grid(grid1);
    }
    cout << "No";
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
5
.....
..#..
.###.
.....
.....
.....
.....
....#
...##
....#
)",
        R"(
5
#####
##..#
#..##
#####
.....
#####
#..##
##..#
#####
.....
)"
    };

    for (const auto& input : inputs) {
        istringstream is(input);
        sol(is);
        cout << endl;
    }
}

#else

int main() {
    sol(std::cin);
}

#endif // LOCAL_MACHINE
