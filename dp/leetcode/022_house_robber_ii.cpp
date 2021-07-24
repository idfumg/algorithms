#include "../../template.hpp"

int rec(const vi& arr, const int n, const int k) {
    if (n <= 0) return 0;
    if (n == 1 and not k) return arr[n - 1];
    if (n == 1 and k) return 0;
    return max(rec(arr, n - 1, k),
               rec(arr, n - 2, k) + arr[n - 1]);
}

int rec(const vi& arr) {
    const int n = arr.size();
    return max(rec(arr, n - 1, 0),
               rec(arr, n - 2, 1) + arr[n - 1]);
}

int tab(const vi& arr) {
    const int n = arr.size();
    if (n == 1) return arr[0];
    vvi dp(n + 1, vi(2));
    dp[1][0] = arr[0];
    for (int i = 2; i <= n; ++i) {
        for (int k : {0, 1}) {
            if (i == 1 and not k) dp[i][k] = arr[i - 1];
            else dp[i][k] = max(dp[i - 1][k], arr[i - 1] + dp[i - 2][k]);
        }
    }
    return max(dp[n - 1][0], arr[n - 1] + dp[n - 2][1]);
}

int main() { TimeMeasure _; __x();
    cout << rec({2,3,2}) << endl; // 3
    cout << rec({1,2,3,1}) << endl; // 4
    cout << rec({0}) << endl; // 0
    cout << rec({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72}) << endl; // 0
    cout << endl;
    cout << tab({2,3,2}) << endl; // 3
    cout << tab({1,2,3,1}) << endl; // 4
    cout << tab({0}) << endl; // 0
    cout << tab({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72}) << endl; // 0
}
