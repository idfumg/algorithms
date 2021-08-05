#include "../../template.hpp"

int rec(vi a, vi b, int m, int n) {
    if (m == 0 or n == 0) return 0;
    return max(rec(a, b, m - 1, n) + a[m - 1] * 0,
               rec(a, b, m - 1, n - 1) + a[m - 1] * b[n - 1]);
}

int rec(vi a, vi b) {
    return rec(a, b, a.size(), b.size());
}

int tab(vi a, vi b) {
    int m = a.size();
    int n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    vi arr11 = {2, 3, 1, 7, 8}, arr12 = {3, 6, 7};
    vi arr21 = {1, 2, 3, 6, 1, 4}, arr22 = {4, 5, 1};

    cout << rec(arr11, arr12) << endl; // 107
    cout << rec(arr21, arr22) << endl; // 46
    cout << endl;
    cout << tab(arr11, arr12) << endl; // 107
    cout << tab(arr21, arr22) << endl; // 46
}
