#include "../../template.hpp"

bool IsIncreasing(int n) {
    int prev = n % 10;
    for (n /= 10; n > 0; n /= 10) {
        if (n % 10 > prev) return false;
        prev = n % 10;
    }
    return true;
}

int naive(int n) {
    int ans = 0;
    for (int i = 0; i <= pow(10, n); ++i) {
        if (IsIncreasing(i)) {
            ++ans;
        }
    }
    return ans;
}

int rec(int n, int digit) {
    if (n == 0) return 1;
    if (digit > 9) return 0;
    return rec(n - 1, digit) + rec(n, digit + 1);
}

int rec(int n) {
    return rec(n, 0);
}

int tab(int n) {
    vvi dp(n + 1, vi(11));
    for (int i = 0; i <= n; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (i == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
        }
    }
    return dp[n][0];
}

int rec2(int n, int prev) {
    if (n == 0) return 1;
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        if (i >= prev) {
            ans += rec2(n - 1, i);
        }
    }
    return ans;
}

int rec2(int n) {
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += rec2(n - 1, i);
    }
    return ans;
}

int tab2(int n) {
    vvi dp(n + 1, vi(10));
    for (int i = 0; i <= n; ++i) {
        for (int prev = 0; prev < 10; ++prev) {
            if (i == 0) {
                dp[i][prev] = 1;
            }
            else {
                for (int k = 0; k < 10; ++k) {
                    if (k >= prev) {
                        dp[i][prev] += dp[i - 1][k];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < 10; ++k) {
        ans += dp[n - 1][k];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << naive(1) << endl; // 10
    cout << naive(2) << endl; // 55
    cout << naive(3) << endl; // 220
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << '\n';
    cout << tab(1) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
    cout << '\n';
    cout << rec2(1) << endl;
    cout << rec2(2) << endl;
    cout << rec2(3) << endl;
    cout << '\n';
    cout << tab2(1) << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
