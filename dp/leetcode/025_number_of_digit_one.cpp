#include "../../template.hpp"

ll naive(ll n) {
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i; j > 0; j /= 10) {
            ans += j % 10 == 1;
        }
    }
    return ans;
}

ll rec_(ll n) {
    if (n == 0) return 0;
    return (n % 10 == 1) + rec_(n / 10);
}

ll rec(ll n) {
    if (n == 0) return 0;
    return rec(n - 1) + rec_(n);
}

ll tab(ll n) {
    vi count(n + 1);
    vi dp(n + 1);
    for (ll i = 1; i <= n; ++i) {
        count[i] = (i % 10 == 1) + count[i / 10];
        dp[i] = dp[i - 1] + count[i];
    }
    return dp[n];
}

ll fast(ll n) {
    if (n == 0) return 0;
    ll count = 0;
    for (ll factor = 1; n / factor > 0; factor *= 10) {
        const ll low = n - (n / factor) * factor;
        const ll d = (n / factor) % 10;
        const ll high = n / (factor * 10);

        switch (d) {
        case 0:
            count += high * factor;
            break;
        case 1:
            count += high * factor + (low + 1);
            break;
        default:
            count += (high + 1) * factor;
        }
    }
    return count;
}

ll fast_rec(const ll n) {
    if (n <= 0) return 0;
    if (n < 10) return 1;
    const ll base = pow(10, (ll)log10(n));
    const ll first = n / base;
    return fast_rec(base - 1) * first + (first == 1 ? (n - base + 1) : base) + fast_rec(n % base);
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
    cout << endl;
    cout << fast_rec(13) << endl; // 6
    cout << fast_rec(0) << endl; // 0
    cout << fast_rec(20) << endl; // 12
    cout << fast_rec(723) << endl; // 253
    cout << fast_rec(224883294) << endl; // 287944060
    cout << fast_rec(824883294) << endl; // 767944060
}
