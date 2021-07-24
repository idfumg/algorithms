#include "../../template.hpp"

void PrintUsed(vi arr, vb used) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            cout << arr[i] << ' ';
        }
    }
    cout << "and ";
    for (int i = 0; i < n; ++i) {
        if (not used[i]) {
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}

bool rec(vi arr, int sum, int n, vb& used) {
    if (sum == 0) {
        PrintUsed(arr, used);
        return true;
    }
    if (n == 0 or sum < 0) return false;
    bool a = rec(arr, sum, n - 1, used);
    used[n - 1] = true;
    bool b = rec(arr, sum - arr[n - 1], n - 1, used);
    used[n - 1] = false;
    return a or b;
}

bool rec(vi arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if (total % 2 != 0) return false;
    int sum = total / 2;
    int n = arr.size();
    vb used(n);
    return rec(arr, sum, arr.size(), used);
}

bool tab(vi arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if (total % 2 != 0) return false;
    int sum = total / 2;
    int n = arr.size();
    vvi dp(sum + 1, vi(n + 1));
    vvvi prev(sum + 1, vvi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
            }
            else if (j == 0) {
                dp[i][j] = false;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (dp[i][j]) {
                    prev[i][j] = {i, j - 1, 0};
                }
                if (i >= arr[j - 1] and not dp[i][j]) {
                    dp[i][j] = dp[i - arr[j - 1]][j - 1];
                    if (dp[i][j]) {
                        prev[i][j] = {i - arr[j - 1], j - 1, 1};
                    }
                }
            }
        }
    }
    vb used(n);
    for (vi at = prev[sum][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            used[at[1]] = true;
        }
    }
    PrintUsed(arr, used);
    return dp[sum][n];
}

void PrintPaths(vi arr, vvi dp, vvvvi prev, int m, int n, vb& used) {
    if (prev[m][n].empty()) {
        PrintUsed(arr, used);
        return;
    }
    for (vi path : prev[m][n]) {
        if (path[2] == 1) {
            used[path[1]] = true;
        }
        PrintPaths(arr, dp, prev, path[0], path[1], used);
        if (path[2] == 1) {
            used[path[1]] = false;
        }
    }
}

bool tab2(vi arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if (total % 2 != 0) return false;
    int sum = total / 2;
    int n = arr.size();
    vvi dp(sum + 1, vi(n + 1));
    vvvvi prev(sum + 1, vvvi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
            }
            else if (j == 0) {
                dp[i][j] = false;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (dp[i][j - 1]) {
                    prev[i][j].push_back({i, j - 1, 0});
                }
                if (i >= arr[j - 1]) {
                    dp[i][j] = dp[i - arr[j - 1]][j - 1];
                    if (dp[i - arr[j - 1]][j - 1]) {
                        prev[i][j].push_back({i - arr[j - 1], j - 1, 1});
                    }
                }
            }
        }
    }
    vb used(n);
    PrintPaths(arr, dp, prev, sum, n, used);
    return dp[sum][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 5, 1, 11};
    vi arr2 = {1, 5, 3};
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << endl;
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
}
