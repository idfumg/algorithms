#include "../../template.hpp"

int naive(vi& arr1, vi& arr2, int m, int n) {
    if (m == 0 or n == 0) return 0;
    if (arr1[m - 1] == arr2[n - 1]) return naive(arr1, arr2, m - 1, n - 1) + 1;
    return max(naive(arr1, arr2, m - 1, n), naive(arr1, arr2, m, n - 1));
}

int naive(vi& arr1, vi& arr2, int k) {
    int m = arr1.size(), n = arr2.size();
    int lcs = naive(arr1, arr2, m, n);
    int minlen = min(m, n);
    return (minlen - lcs < k ? minlen - lcs : k) + lcs;
}

int tab_naive(vi arr1, vi arr2, int k) {
    int m = arr1.size();
    int n = arr2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = dp[m][n];
    if (ans + k <= min(m, n)) return ans + k;
    return ans;
}

int tab_straight(vi arr1, vi arr2, int K) {
    int m = arr1.size();
    int n = arr2.size();
    vvvi dp(m + 1, vvi(n + 1, vi(K + 1)));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j][0] = 1 + dp[i - 1][j - 1][0];
            }
            else {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= K; ++k) {
                if (arr1[i - 1] == arr2[j - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k];
                }
                else {
                    dp[i][j][k] = max({
                            dp[i - 1][j][k],
                            dp[i][j - 1][k],
                            1 + dp[i - 1][j - 1][k - 1]});
                }
            }
        }
    }
    return dp[m][n][K];
}

int tab_elems(vi arr1, vi arr2, int K) {
    int m = arr1.size();
    int n = arr2.size();
    vvvi dp(m + 1, vvi(n + 1, vi(K + 1)));
    vvvvi prev(m + 1, vvvi(n + 1, vvi(K + 1)));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j][0] = 1 + dp[i - 1][j - 1][0];
                prev[i][j][0] = {i - 1, j - 1, 0, 1};
            }
            else {
                if (dp[i - 1][j][0] > dp[i][j - 1][0]) {
                    dp[i][j][0] = dp[i - 1][j][0];
                    prev[i][j][0] = {i - 1, j, 0, 0};
                }
                else {
                    dp[i][j][0] = dp[i][j - 1][0];
                    prev[i][j][0] = {i, j - 1, 0, 0};
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= K; ++k) {
                if (arr1[i - 1] == arr2[j - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k];
                    prev[i][j][k] = {i - 1, j - 1, k, 1};
                }
                else {
                    dp[i][j][k] = max({
                            dp[i - 1][j][k],
                            dp[i][j - 1][k],
                            1 + dp[i - 1][j - 1][k - 1]});
                    if (dp[i][j][k] == dp[i - 1][j][k]) {
                        prev[i][j][k] = {i - 1, j, k, 0};
                    }
                    else if (dp[i][j][k] == dp[i][j - 1][k]) {
                        prev[i][j][k] = {i, j - 1, k, 0};
                    }
                    else {
                        prev[i][j][k] = {i - 1, j - 1, k - 1, 2};
                    }
                }
            }
        }
    }
    cout << '[' << ' ';
    for (vi at = prev[m][n][K]; not at.empty(); at = prev[at[0]][at[1]][at[2]]) {
        if (at[3] == 1) {
            cout << arr1[at[0]] << ' ';
        }
        else if (at[3] == 2) {
            cout << '+' << arr1[at[0]] << ' ';
        }
    }
    cout << ']' << ' ';
    return dp[m][n][K];
}

int main() { TimeMeasure _; __x();
    vi arr11 = {8, 3}, arr12 = {1, 3}; int k1 = 1;
    vi arr21 = {1, 2, 3, 4, 5}, arr22 = {5, 3, 1, 4, 2}; int k2 = 1;
    vi arr31 = {1, 2, 3, 4}, arr32 = {5, 1, 2, 3, 8}; int k3 = 1;

    cout << naive(arr11, arr12, k1) << endl; // 2
    cout << naive(arr21, arr22, k2) << endl; // 3
    cout << naive(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_naive(arr11, arr12, k1) << endl; // 2
    cout << tab_naive(arr21, arr22, k2) << endl; // 3
    cout << tab_naive(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_straight(arr11, arr12, k1) << endl; // 2
    cout << tab_straight(arr21, arr22, k2) << endl; // 3
    cout << tab_straight(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_elems(arr11, arr12, k1) << endl; // 2
    cout << tab_elems(arr21, arr22, k2) << endl; // 3
    cout << tab_elems(arr31, arr32, k3) << endl; // 4
}
