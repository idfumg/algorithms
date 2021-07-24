#include "../../template.hpp"

int tab(const int n) {
    if (n == 0) return 0;
    vi dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (2 * i <= n) dp[2 * i] = dp[i];
        if (2 * i + 1 <= n) dp[2 * i + 1] = dp[i] + dp[i + 1];
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab(7) << endl; // 3
    cout << tab(2) << endl; // 1
    cout << tab(3) << endl; // 2
    cout << tab(0) << endl; // 0
    cout << tab(1) << endl; // 1
    cout << tab(2) << endl; // 1
}
