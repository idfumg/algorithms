#include "../../template.hpp"

/*
N0 = N
N1 = N - K + 1 = N - (K - 1)
N2 = N - K + 1 - K + 1 = N - (K - 1) * 2
Ni = N - (K - 1) * i
=> N - (K - 1) * i = m
=> N - m = (K - 1) * i
=> (N - m) % (K - 1) == 0
*/
int rec(const vi& arr, const int K, const vi& prefix, int i, int j, int m) {
    if ((j - i + 1 - m) % (K - 1) != 0) return INF;
    if (i == j and m == 1) return 0;
    if (i == j and m != 1) return INF;
    if (m == 1) return rec(arr, K, prefix, i, j, K) + prefix[j] - prefix[i - 1];
    int ans = INF;
    for (int mid = i; mid < j; mid += K - 1) {
        ans = min(ans,
                  rec(arr, K, prefix, i, mid, 1) +
                  rec(arr, K, prefix, mid + 1, j, m - 1));
    }
    return ans;
}

int rec(const vi& arr, const int K) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    const int res = rec(arr, K, prefix, 1, n, 1);
    return res == INF ? -1 : res;
}

int tab(const vi& arr, const int K) {
    const int n = arr.size();

    if ((n - 1) % (K - 1) != 0) return -1;

    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    vvvi dp(n + 1, vvi(n + 1, vi(K + 1, INF)));

    for (int i = 1; i <= n; ++i) {
        dp[i][i][1] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
            for (int k = 2; k <= K; ++k) {
                for (int p = i; p < j; ++p) {
                    dp[i][j][k] = min(dp[i][j][k],
                                      dp[i][p][1] + dp[p + 1][j][k - 1]);
                }
            }
            dp[i][j][1] = dp[i][j][K] + prefix[j] - prefix[i - 1];
        }
    }

    return dp[1][n][1];
}

int tab2(const vi& arr, const int K) {
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
            for (int p = i; p < j; p += K - 1) {
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
    cout << rec({3,2,4,1}, 2) << endl; // 20
    cout << rec({3,2,4,1}, 3) << endl; // -1
    cout << rec({3,5,1,2,6}, 3) << endl; // 25
    cout << rec({6,4,9,9,9,7}, 3) << '\n'; // -1
    cout << rec({1,2}, 2) << '\n'; // 3
    cout << rec({9,8,3,2,9,4}, 2) << '\n'; // 88
    cout << rec({6,4,4,6}, 2) << '\n'; // 40
    cout << endl;
    cout << tab({3,2,4,1}, 2) << endl; // 20
    cout << tab({3,2,4,1}, 3) << endl; // -1
    cout << tab({3,5,1,2,6}, 3) << endl; // 25
    cout << tab({6,4,9,9,9,7}, 3) << '\n'; // -1
    cout << tab({1,2}, 2) << '\n'; // 3
    cout << tab({9,8,3,2,9,4}, 2) << '\n'; // 88
    cout << tab({6,4,4,6}, 2) << '\n'; // 40
    cout << endl;
    cout << tab2({3,2,4,1}, 2) << endl; // 20
    cout << tab2({3,2,4,1}, 3) << endl; // -1
    cout << tab2({3,5,1,2,6}, 3) << endl; // 25
    cout << tab2({6,4,9,9,9,7}, 3) << '\n'; // -1
    cout << tab2({1,2}, 2) << '\n'; // 3
    cout << tab2({9,8,3,2,9,4}, 2) << '\n'; // 88
    cout << tab2({6,4,4,6}, 2) << '\n'; // 40
}
