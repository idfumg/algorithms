#include "../../template.hpp"

int rec(const vi& arr, const int k, const int n) {
    if (n <= 0) return 0;
    int ans = -INF, maxi = -INF;
    for (int i = 1; i <= k and n - i >= 0; ++i) {
        maxi = max(maxi, arr[n - i]);
        ans = max(ans, maxi * i + rec(arr, k, n - i));
    }
    return ans;
}

int rec(const vi& arr, const int k) {
    return rec(arr, k, arr.size());
}

int tab(const vi& arr, const int k) {
    const int n = arr.size();
    vi dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int maxi = -INF;
        for (int count = 1; count <= k and i - count >= 0; ++count) {
            maxi = max(maxi, arr[i - count]);
            dp[i] = max(dp[i], maxi * count + dp[i - count]);
        }
    }
    return dp[n];
}

int rec_(const vi& arr, const int i, const int count) {
    return *max_element(arr.begin() + i - 1, arr.begin() + i + count - 1);
}

int rec2(const vi& arr, const int n, const int count, const int k) {
    if (count > k) return -INF;
    if (n == 0 and count != 1) return -INF;
    if (n == 0 and count == 1) return 0;
    return max(
        rec2(arr, n - 1, count + 1, k),
        rec2(arr, n - 1, 1, k) + rec_(arr, n, count) * count);
}

int rec2(const vi& arr, const int k) {
    return rec2(arr, arr.size(), 1, k);
}

int tab2(const vi& arr, const int K) {
    const int n = arr.size();
    vvi maxs(n + 2, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        maxs[i][i] = arr[i - 1];
    }
    for (int i = 2; i <= n; ++i) {
        maxs[i - 1][i] = max(arr[i - 2], arr[i - 1]);
    }
    for (int k = 3; k <= n; ++k) {
        for (int i = 1, j = i + k - 1; j <= n; ++i, ++j) {
            maxs[i][j] = max({arr[i - 1], maxs[i + 1][j], maxs[i][j - 1], arr[j - 1], maxs[i + 1][j - 1]});
        }
    }
    vvi dp(n + 1, vi(K + 2, -INF));
    for (int i = 0; i <= n; ++i) {
        for (int k = K; k >= 1; --k) {
            if (i == 0 and k != 1) {
                dp[i][k] = -INF;
            }
            else if (i == 0 and k == 1) {
                dp[i][k] = 0;
            }
            else {
                dp[i][k] = max(dp[i - 1][k + 1],
                               (i + k - 1 <= n ? dp[i - 1][1] + maxs[i][i + k - 1] * k : 0));
            }
        }
    }
    return dp[n][1];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << rec({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << rec({1}, 1) << endl; // 1
    cout << endl;
    cout << tab({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << tab({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << tab({1}, 1) << endl; // 1
    cout << endl;
    cout << rec2({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << rec2({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << rec2({1}, 1) << endl; // 1
    cout << endl;
    cout << tab2({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << tab2({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << tab2({1}, 1) << endl; // 1
}
