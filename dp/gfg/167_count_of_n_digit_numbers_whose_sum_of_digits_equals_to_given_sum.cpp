#include "../../template.hpp"

int rec_(int n, int total) {
    if (n == 0 and total == 0) return 1;
    if (n == 0 or total < 0) return 0;
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += rec_(n - 1, total - i);
    }
    return count;
}

int rec(int n, int total) {
    int count = 0;
    for (int i = 1; i < 10; ++i) {
        count += rec_(n - 1, total - i);
    }
    return count;
}

int rec2(int n, int total, int i) {
    if (n == 0 and total == 0) return 1;
    if (n == 0 or total < 0 or i > 9) return 0;
    return rec2(n - 1, total - i, 0) + rec2(n, total, i + 1);
}

int rec2(int n, int total) {
    return rec2(n, total, 1);
}

int tab(int n, int total) {
    vvi dp(n + 1, vi(total + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            if (i == 0 and j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = 0;
            }
            else {
                for (int k = i == n and j == total; k < 10; ++k) {
                    if (j >= k) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
    }
    return dp[n][total];
}

int tab2(int n, int total) {
    vvvi dp(n + 1, vvi(total + 1, vi(11)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            for (int k = 9; k >= 0; --k) {
                if (i == 0 and j == 0) {
                    dp[i][j][k] = 1;
                }
                else if (i == 0) {
                    dp[i][j][k] = 0;
                }
                else {
                    if (j >= k) {
                        dp[i][j][k] += dp[i - 1][j - k][0];
                    }
                    dp[i][j][k] += dp[i][j][k + 1];
                }
            }
        }
    }
    return dp[n][total][1];
}

int tab3(int n, int sum) {
    vvi dp(sum + 1, vi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 0;
            else {
                int ans = 0;
                for (int k = 0; k <= 9; ++k) {
                    if (i >= k) {
                        ans += dp[i - k][j - 1];
                    }
                }
                dp[i][j] = ans;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        if (sum >= i) {
            ans += dp[sum - i][n - 1];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec(2, 2) << endl; // 2
    cout << rec(2, 5) << endl; // 5
    cout << rec(3, 6) << endl; // 21
    cout << endl;
    cout << rec2(2, 2) << endl;
    cout << rec2(2, 5) << endl;
    cout << rec2(3, 6) << endl;
    cout << endl;
    cout << tab(2, 2) << endl;
    cout << tab(2, 5) << endl;
    cout << tab(3, 6) << endl;
    cout << endl;
    cout << tab2(2, 2) << endl;
    cout << tab2(2, 5) << endl;
    cout << tab2(3, 6) << endl;
    cout << endl;
    cout << tab3(2, 2) << endl;
    cout << tab3(2, 5) << endl;
    cout << tab3(3, 6) << endl;
}
