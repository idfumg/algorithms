#include "../../template.hpp"

int naive(int number) {
    int count = 0;
    for (int i = 1; i <= number; ++i) {
        for (int n = i; n > 0; n /= 10) {
            if (n % 10 == 1) {
                ++count;
            }
        }
    }
    return count;
}

int rec_(int n) {
    if (n <= 0) return 0;
    return rec_(n / 10) + (n % 10 == 1 ? 1 : 0);
}

int rec(int n) {
    if (n <= 0) return 0;
    int digits = log10(n);
    int x = digits / 2;
    int y = pow(10, x);
    return rec_(n / y) + rec_(n % y) + rec(n - 1);
}

int tab(const int n) {
    if (n == 0) return 0;
    if (n < 10) return 1;
    vi dp_(1e9);
    vi dp(2);
    int idx = 0;
    dp[1] = dp_[1] = 1;
    for (int i = 2; i <= n; ++i) {
        idx = i & 1;
        dp_[i] = dp_[i / 10] + (i % 10 == 1);
        dp[idx] = dp_[i] + dp[1 - idx];
    }
    return dp[idx];
}

long long fast(int n) {
    if (n == 0) return 0;
    long long count = 0;
    for (long long factor = 1; n / factor> 0; factor *= 10) {
        const long long lowern = n - (n / factor) * factor;
        const long long currentn = (n / factor) % 10;
        const long long highern = n / (factor * 10);

        switch (currentn) {
        case 0:
            count += highern * factor;
            break;
        case 1:
            count += highern * factor + (lowern + 1);
            break;
        default:
            count += (highern + 1) * factor;
        }
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << naive(13) << endl; // 6
    cout << naive(0) << endl; // 0
    cout << naive(20) << endl; // 12
    cout << naive(224883294) << endl; // 287944060
    //cout << naive(824883294) << endl; // 767944060
    cout << endl;
    cout << rec(13) << endl; // 6
    cout << rec(0) << endl; // 0
    cout << rec(20) << endl; // 12
    //cout << rec(824883294) << endl; // 767944060
    cout << endl;
    cout << tab(13) << endl; // 6
    cout << tab(0) << endl; // 0
    cout << tab(20) << endl; // 12
    cout << tab(723) << endl; // 253
    cout << tab(224883294) << endl; // 287944060
    //cout << tab(824883294) << endl; // 767944060
    cout << endl;
    cout << fast(13) << endl; // 6
    cout << fast(0) << endl; // 0
    cout << fast(20) << endl; // 12
    cout << fast(723) << endl; // 253
    cout << fast(224883294) << endl; // 287944060
    cout << fast(824883294) << endl; // 767944060
}
