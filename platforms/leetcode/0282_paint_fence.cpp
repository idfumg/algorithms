#include "../../template.hpp"

int sol(int n, int k, int c) {
    if (n == 0) return 0;
    if (n == 1) return k;
    if (n == 2 and c == 1) return k * (k - 1);
    if (n == 2 and c == 2) return k;
    if (c == 1) return sol(n - 1, k, 1) * (k - 1) + sol(n - 1, k, 2) * (k - 1);
    return sol(n - 1, k, 1) * 1;
}

int sol(int n, int k) {
    if (n == 1) return k;
    return sol(n, k, 1) + sol(n, k, 2);
}

int sol2(int n, int k) {
    if (n == 1) return k;
    vvll dp(2, vll(2));
    dp[0][0] = k;
    dp[0][1] = k;
    dp[1][0] = k * (k - 1);
    dp[1][1] = k;
    int idx = 0;
    for (int i = 2; i <= n; ++i) {
        idx = i & 1;
        for (int c : {0, 1}) {
            if (c == 0) dp[idx][0] = dp[1 - idx][0] * (k - 1) + dp[1 - idx][1] * (k - 1);
            else dp[idx][1] = dp[1 - idx][0] * 1;
        }
    }
    return dp[1 - idx][0] + dp[1 - idx][1];
}

int with_same(int n, int k);

int with_diff(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k * (k - 1);
    return with_same(n - 1, k) * (k - 1) + with_diff(n - 1, k) * (k - 1);
}

int with_same(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k;
    return with_diff(n - 1, k) * 1;
}

int sol3(int n, int k) {
    if (n == 1) return k;
    return with_same(n, k) + with_diff(n, k);
}

int sol4(int n, int k) {
    if (n == 1) return k;
    vi dpsame(n + 1);
    vi dpdiff(n + 1);
    dpsame[1] = k;
    dpsame[2] = k;
    dpdiff[1] = k;
    dpdiff[2] = k * (k - 1);
    for (int i = 3; i <= n; ++i) {
        dpsame[i] = dpdiff[i - 1] * 1;
        dpdiff[i] = dpsame[i - 1] * (k - 1) + dpdiff[i - 1] * (k - 1);
    }
    return dpsame[n] + dpdiff[n];
}

int main() { TimeMeasure _; __x();
    cout << sol(3, 2) << endl; // 6
    cout << sol(1, 1) << endl; // 1
    cout << sol(7, 2) << endl; // 42
    cout << sol(2, 46340) << endl; // 2147395600
    cout << endl;
    cout << sol2(3, 2) << endl; // 6
    cout << sol2(1, 1) << endl; // 1
    cout << sol2(7, 2) << endl; // 42
    cout << sol2(2, 46340) << endl; // 2147395600
    cout << endl;
    cout << sol3(3, 2) << endl; // 6
    cout << sol3(1, 1) << endl; // 1
    cout << sol3(7, 2) << endl; // 42
    cout << sol3(2, 46340) << endl; // 2147395600
    cout << endl;
    cout << sol4(3, 2) << endl; // 6
    cout << sol4(1, 1) << endl; // 1
    cout << sol4(7, 2) << endl; // 42
    cout << sol4(2, 46340) << endl; // 2147395600
}
