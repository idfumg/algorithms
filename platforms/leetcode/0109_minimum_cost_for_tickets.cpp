#include "../../template.hpp"

static const vi days = {1, 7, 30};

int rec(const vi& arr, const vi& costs, const int n) {
    if (n <= 0) return 0;
    int ans = INF;
    for (int i = 0; i < 3; ++i) {
        const int passed = max(0, arr[n - 1] - days[i]);
        int newn = n;
        while (newn > 0 and passed < arr[newn - 1]) --newn;
        ans = min(ans, rec(arr, costs, newn) + costs[i]);
    }
    return ans;
}

int rec(const vi& arr, const vi& costs) {
    return rec(arr, costs, arr.size());
}

int tab(const vi& arr, const vi& costs) {
    const int n = arr.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int ans = INF;
        for (int j = 0; j < 3; ++j) {
            const int passed = max(0, arr[i - 1] - days[j]);
            const auto newn = upper_bound(arr.cbegin(), arr.cbegin() + i, passed);
            if (newn != arr.cend()) {
                const int d = max(0, (int)distance(arr.cbegin(), newn));
                ans = min(ans, dp[d] + costs[j]);
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,4,6,7,8,20}, {2,7,15}) << endl; // 11
    cout << rec({1,2,3,4,5,6,7,8,9,10,30,31}, {2,7,15}) << endl; // 17
    cout << endl;
    cout << tab({1,4,6,7,8,20}, {2,7,15}) << endl; // 11
    cout << tab({1,2,3,4,5,6,7,8,9,10,30,31}, {2,7,15}) << endl; // 17
}
