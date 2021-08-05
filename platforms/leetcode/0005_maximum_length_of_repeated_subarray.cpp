#include "../../template.hpp"

int get_count(const vi& a, const vi& b, const int m, const int n) {
    if (m == 0 or n == 0) return 0;
    return a[m - 1] == b[n - 1] ? 1 + get_count(a, b, m - 1, n - 1) : 0;
}

int rec(const vi& a, const vi& b, const int m, const int n) {
    if (m == 0 or n == 0) return 0;
    if (a[m - 1] == b[n - 1]) {
        const int k = get_count(a, b, m, n);
        return max({k, rec(a, b, m - 1, n), rec(a, b, m, n - 1)});
    }
    return max(rec(a, b, m - 1, n), rec(a, b, m, n - 1));
}

int rec(const vi& a, const vi& b) {
    return rec(a, b, a.size(), b.size());
}

int tab(const vi& a, const vi& b) {
    const int m = a.size(), n = b.size();
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0 or j == 0) count[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) count[i][j] = 1 + count[i - 1][j - 1];
            else count[i][j] = 0;
        }
    }

    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0 or j == 0) dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = max({count[i][j], dp[i - 1][j], dp[i][j - 1]});
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,2,3,2,1}, {3,2,1,4,7}) << endl; // 3
    cout << rec({0,0,0,0,0}, {0,0,0,0,0}) << endl; // 5
    cout << rec({3,2,5,2,1}, {3,2,1,4,7}) << endl; // 2
    cout << rec({0,0,0,0,0,0,1,0,0,0}, {0,0,0,0,0,0,0,1,0,0}) << endl; // 9
    cout << endl;
    cout << tab({1,2,3,2,1}, {3,2,1,4,7}) << endl; // 3
    cout << tab({0,0,0,0,0}, {0,0,0,0,0}) << endl; // 5
    cout << tab({3,2,5,2,1}, {3,2,1,4,7}) << endl; // 2
    cout << tab({0,0,0,0,0,0,1,0,0,0}, {0,0,0,0,0,0,0,1,0,0}) << endl; // 9
}
