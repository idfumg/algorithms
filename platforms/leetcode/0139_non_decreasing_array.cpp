#include "../../template.hpp"

int sol(const vi& arr, const int n, const int k) {
    if (k < 0 or n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return k > 0 or arr[n] >= arr[n - 1];

    if (arr[n] >= arr[n - 1] and sol(arr, n - 1, k)) return 1;
    if (arr[n] >= arr[n - 2] and sol(arr, n - 2, k - 1)) return 1;
    return n == arr.size() - 1 and sol(arr, n - 1, k - 1);
}

int sol(const vi& arr) {
    return sol(arr, arr.size() - 1, 1);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvi dp(n, vi(2));
    for (int i = 0; i < n; ++i) {
        for (const int k : {1, 0}) {
            if (i == 0) dp[i][k] = 1;
            else if (i == 1) dp[i][k] = k > 0 or arr[i] >= arr[i - 1];
            else if (arr[i] >= arr[i - 1] and dp[i - 1][k]) dp[i][k] = 1;
            else if (k > 0 and arr[i] >= arr[i - 2] and dp[i - 2][k - 1]) dp[i][k] = 1;
            else if (k > 0) dp[i][k] = (i == n - 1) and dp[i - 1][k - 1];
        }
    }
    return dp[n - 1][1];
}

int main() { TimeMeasure _; __x();
    cout << sol({4,2,3}) << endl; // 1
    cout << sol({2,4,3}) << endl; // 1
    cout << sol({4,2,1}) << endl; // 0
    cout << sol({3,4,2,3}) << endl; // 0
    cout << sol({-1,4,2,3}) << endl; // 1
    cout << sol({5,7,1,8}) << endl; // 1
    cout << sol({3,3,2,2}) << endl; // 0
    cout << sol({1}) << endl; // 1
    cout << sol({1,5,4,6,7,10,8,9}) << endl; // 0
    cout << sol({12,8,15,11,13,14}) << endl; // 0
    cout << sol({3,2,3,2,4}) << endl; // 0
    cout << sol({1,2,4,5,3}) << endl; // 1
    cout << endl;
    cout << tab({4,2,3}) << endl; // 1
    cout << tab({2,4,3}) << endl; // 1
    cout << tab({4,2,1}) << endl; // 0
    cout << tab({3,4,2,3}) << endl; // 0
    cout << tab({-1,4,2,3}) << endl; // 1
    cout << tab({5,7,1,8}) << endl; // 1
    cout << tab({3,3,2,2}) << endl; // 0
    cout << tab({1}) << endl; // 1
    cout << tab({1,5,4,6,7,10,8,9}) << endl; // 0
    cout << tab({12,8,15,11,13,14}) << endl; // 0
    cout << tab({3,2,3,2,4}) << endl; // 0
    cout << tab({1,2,4,5,3}) << endl; // 1
}
