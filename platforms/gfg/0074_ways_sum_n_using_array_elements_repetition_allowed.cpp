#include "../../template.hpp"

int rec(vi arr, int total) {
    if (total == 0) return 1;
    if (total < 0) return 0;
    int n = arr.size();
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        count += rec(arr, total - arr[i - 1]);
    }
    return count;
}

int tab(vi arr, int total) {
    int n = arr.size();
    vi dp(total + 1);
    dp[0] = 1;
    for (int i = 1; i <= total; ++i) {
        for (int p = 1; p <= n; ++p) {
            if (i >= arr[p - 1]) {
                dp[i] += dp[i - arr[p - 1]];
            }
        }
    }
    return dp[total];
}

int rec2(vi arr, int total, int i) {
    int n = arr.size();
    if (total == 0) return 1;
    if (total < 0 or i > n) return 0;
    return rec2(arr, total - arr[i - 1], 1) + rec2(arr, total, i + 1);
}

int rec2(vi arr, int total) {
    return rec2(arr, total, 1);
}

int tab2(vi arr, int total) {
    int n = arr.size();
    vvi dp(total + 1, vi(n + 2));
    for (int i = 0; i <= total; ++i) {
        for (int j = n; j >= 1; --j) {
            if (i == 0) dp[i][j] = 1;
            else {
                if (i >= arr[j - 1]) {
                    dp[i][j] += dp[i - arr[j - 1]][1];
                }
                dp[i][j] += dp[i][j + 1];
            }
        }
    }
    return dp[total][1];
}

int rec(vi arr, int target, int n) {
    if (target == 0) return 1;
    if (n == 0 or target < 0) return 0;
    return rec(arr, target, n - 1) + rec(arr, target - arr[n - 1], arr.size());
}

int rec3(vi arr, int target) {
    return rec(arr, target, arr.size());
}

int tab3(vi arr, int target) {
    int n = arr.size();
    vvi dp(target + 1, vi(n + 1));
    for (int i = 0; i <= target; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (i >= arr[j - 1]) {
                    dp[i][j] += dp[i - arr[j - 1]][n];
                }
            }
        }
    }
    return dp[target][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 6}; int sum1 = 7; // 6
    vi arr2 = {12, 3, 1, 9}; int sum2 = 14; // 150

    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << '\n';
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << '\n';
    cout << rec2(arr1, sum1) << endl;
    cout << rec2(arr2, sum2) << endl;
    cout << '\n';
    cout << tab2(arr1, sum1) << endl;
    cout << tab2(arr2, sum2) << endl;
    cout << '\n';
    cout << rec3(arr1, sum1) << endl;
    cout << rec3(arr2, sum2) << endl;
    cout << '\n';
    cout << tab3(arr1, sum1) << endl;
    cout << tab3(arr2, sum2) << endl;
}
