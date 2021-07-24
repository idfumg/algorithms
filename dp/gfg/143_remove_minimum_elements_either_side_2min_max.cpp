#include "../../template.hpp"

pair<vvi, vvi> GetMinsMaxs(vi arr) {
    int n = arr.size();
    vvi mins(n + 1, vi(n + 1));
    vvi maxs(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        mins[i][i] = arr[i - 1];
        maxs[i][i] = arr[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        mins[i][i + 1] = min(arr[i - 1], arr[i]);
        maxs[i][i + 1] = max(arr[i - 1], arr[i]);
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            mins[i][j] = min(mins[i + 1][j], arr[i - 1]);
            maxs[i][j] = max(maxs[i + 1][j], arr[i - 1]);
        }
    }
    return {mins, maxs};
}

int rec(vi arr, vvi& mins, vvi& maxs, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (mins[i][j] * 2 > maxs[i][j]) {
        return 0;
    }
    return min(rec(arr, mins, maxs, i + 1, j),
               rec(arr, mins, maxs, i, j - 1)) + 1;
}

int rec(vi arr) {
    auto [mins, maxs] = GetMinsMaxs(arr);
    return rec(arr, mins, maxs, 1, arr.size());
}

int tab(vi arr) {
    int n = arr.size();
    const auto [mins, maxs] = GetMinsMaxs(arr);
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (mins[i][j] * 2 > maxs[i][j]) dp[i][j] = 0;
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 100, 9, 10, 11, 12, 15, 200}; // 4
    vi arr2 = {4, 7, 5, 6}; // 0
    vi arr3 = {20, 7, 5, 6}; // 1
    vi arr4 = {20, 4, 1, 3}; // 3

    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << '\n';
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
