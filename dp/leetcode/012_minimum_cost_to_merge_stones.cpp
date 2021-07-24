#include "../../template.hpp"

int tab(const vi& arr, const int K) {
    const int n = arr.size();

    if ((n - 1) % (K - 1) != 0) return -1;

    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    vvi dp(n + 1, vi(n + 1));

    for (int k = K; k <= n; ++k) {
        for (int i = 1, j = i + k - 1; j <= n; ++i, ++j) {
            dp[i][j] = INF;
            for (int p = i; p < j; p += (K - 1)) {
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
            }
            if ((j - i) % (K - 1) == 0) {
                dp[i][j] += prefix[j] - prefix[i - 1];
            }
        }
    }

    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << tab({3,2,4,1}, 2) << endl; // 20
    cout << tab({3,2,4,1}, 3) << endl; // -1
    cout << tab({3,5,1,2,6}, 3) << endl; // 25
}
