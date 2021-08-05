#include "../../template.hpp"

ll rec(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;
    ll ans = 0;
    for (int k = 1; k <= n; ++k) {
        ans += rec(k - 1) * rec(n - k);
    }
    return ans;
}

ll tab(int n) {
    vector<ll> dp(n + 4);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for (int i = 4; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i] += dp[k - 1] * dp[i - k];
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec(3) << endl; // 5
    cout << rec(1) << endl; // 1
    cout << rec(10) << endl; // 16796
    cout << rec(19) << endl; // 1767263190
    cout << endl;
    cout << tab(3) << endl; // 5
    cout << tab(1) << endl; // 1
    cout << tab(10) << endl; // 16796
    cout << tab(19) << endl; // 1767263190
}
