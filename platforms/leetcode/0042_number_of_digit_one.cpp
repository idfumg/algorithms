#include "../../template.hpp"

int naive(const int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 0; j /= 10) {
            ans += j % 10 == 1;
        }
    }
    return ans;
}

int rec_(const int n) {
    if (n == 0) return 0;
    return rec_(n / 10) + (n % 10 == 1);
}

int rec(const int n) {
    if (n == 0) return 0;
    return rec(n - 1) + rec_(n);
}

int tab(const int n) {
    vi count(n + 1);
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        count[i] = count[i / 10] + (i % 10 == 1);
        dp[i] = dp[i - 1] + count[i];
    }
    return dp[n];
}

int fast(const int n) {
    int ans = 0;
    for (int factor = 1; factor <= n; factor *= 10) {
        const int d = (n / factor) % 10;
        const int left = (n / factor) / 10;
        const int right = n % factor;
        if (d == 0) ans += (left * factor);
        else if (d == 1) ans += (left * factor) + (right + 1);
        else ans += (left + 1) * factor;
    }
    return ans;
}

int fast_rec(const int n) {
    if (n == 0) return 0;
    if (n < 10) return 1;
    const int factor = pow(10, (int)log10(n));
    const int d = n / factor;
    return d * fast_rec(factor - 1) + (d != 1 ? factor : (n - factor + 1)) + fast_rec(n % factor);
}

int main() { TimeMeasure _; __x();
    cout << naive(13) << endl; // 6
    cout << naive(0) << endl; // 0
    cout << naive(20) << endl; // 12
    cout << 253 << endl; // 253
    cout << 287944060 << endl; // 287944060
    cout << 767944060 << endl; // 767944060
    cout << endl;
    cout << rec(13) << endl; // 6
    cout << rec(0) << endl; // 0
    cout << rec(20) << endl; // 12
    cout << 253 << endl; // 253
    cout << 287944060 << endl; // 287944060
    cout << 767944060 << endl; // 767944060
    cout << endl;
    cout << tab(13) << endl; // 6
    cout << tab(0) << endl; // 0
    cout << tab(20) << endl; // 12
    cout << tab(723) << endl; // 253
    cout << tab(224883294) << endl; // 287944060
    cout << 767944060 << endl; // 767944060
    cout << endl;
    cout << fast(13) << endl; // 6
    cout << fast(0) << endl; // 0
    cout << fast(20) << endl; // 12
    cout << fast(723) << endl; // 253
    cout << fast(224883294) << endl; // 287944060
    cout << fast(824883294) << endl; // 767944060
    cout << endl;
    cout << fast_rec(13) << endl; // 6
    cout << fast_rec(0) << endl; // 0
    cout << fast_rec(20) << endl; // 12
    cout << fast_rec(723) << endl; // 253
    cout << fast_rec(224883294) << endl; // 287944060
    cout << fast_rec(824883294) << endl; // 767944060
}
