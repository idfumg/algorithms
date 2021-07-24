#include "../../template.hpp"

template<class T>
int rec(const vi& arr, const int n, const int k, const int prev, const T& fn) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    if (fn(arr[prev - 1], arr[n - 1]))
        return rec(arr, n - 1, k - 1, n, fn) + rec(arr, n - 1, k, prev, fn);
    return rec(arr, n - 1, k, prev, fn);
}

int rec(const vi& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = n; i >= 1; --i) {
        count += rec(arr, i - 1, 2, i, greater<int>());
    }
    for (int i = n; i >= 1; --i) {
        count += rec(arr, i - 1, 2, i, less<int>());
    }
    return count;
}

int tab(const vi& arr) {
    int n = arr.size();
    int K = 3;
    int count = 0;
    vvvi dp(n + 1, vvi(K + 1, vi(n + 1)));

    {
        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k <= 2; ++k) {
                for (int j = i + 1; j <= n; ++j) {
                    if (i > j) {
                        dp[i][k][j] = 0;
                    }
                    else if (k == 0) {
                        dp[i][k][j] = 1;
                    }
                    else if (i == 0) {
                        dp[i][k][j] = 0;
                    }
                    else if (arr[j - 1] > arr[i - 1]) {
                        dp[i][k][j] = dp[i - 1][k - 1][i] + dp[i - 1][k][j];
                    }
                    else {
                        dp[i][k][j] = dp[i - 1][k][j];
                    }
                    if (i > 0 and k == 2 and i == j - 1) count += dp[i][2][j];
                }
            }
        }
    }
    {
        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k <= 2; ++k) {
                for (int j = i + 1; j <= n; ++j) {
                    if (i > j) {
                        dp[i][k][j] = 0;
                    }
                    else if (k == 0) {
                        dp[i][k][j] = 1;
                    }
                    else if (i == 0) {
                        dp[i][k][j] = 0;
                    }
                    else if (arr[j - 1] < arr[i - 1]) {
                        dp[i][k][j] = dp[i - 1][k - 1][i] + dp[i - 1][k][j];
                    }
                    else {
                        dp[i][k][j] = dp[i - 1][k][j];
                    }
                    if (i > 0 and k == 2 and i == j - 1) count += dp[i][2][j];
                }
            }
        }
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << rec({2,5,3,4,1}) << endl; // 3
    cout << rec({2,1,3}) << endl; // 0
    cout << rec({1,2,3,4}) << endl; // 4
    cout << endl;
    cout << tab({2,5,3,4,1}) << endl; // 3
    cout << tab({2,1,3}) << endl; // 0
    cout << tab({1,2,3,4}) << endl; // 4
}
