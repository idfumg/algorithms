#include "../../template.hpp"

int rec_(int n) {
    if (n == 0) return 0;
    return rec_(n >> 1) + (n & 1);
}

vi rec(int n) {
    vi ans;
    for (int i = 0; i <= n; ++i) {
        ans.push_back(rec_(i));
    }
    return ans;
}

vi tab(const int n) {
    vi dp(n + 1);
    vi ans = {0};
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] + (i & 1);
        ans.push_back(dp[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec(0) << endl; // 0
    cout << rec(2) << endl; // 0,1,1
    cout << rec(5) << endl; // 0,1,1,2,1,2
    cout << endl;
    cout << tab(0) << endl; // 0
    cout << tab(2) << endl; // 0,1,1
    cout << tab(5) << endl; // 0,1,1,2,1,2
}
