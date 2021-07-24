#include "../../template.hpp"

int rec_(int n) {
    if (n == 0) return 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, rec_(n - i) * i);
    }
    return ans;
}

int rec(int n) {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, rec_(n - i) * i);
    }
    return ans;
}

int tab(int n) {
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i] = max(dp[i], dp[i - k] * k);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, dp[n - i] * i);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl; // 1
    cout << rec(10) << endl; // 36
    cout << endl;
    cout << tab(2) << endl; // 1
    cout << tab(10) << endl; // 36
}
