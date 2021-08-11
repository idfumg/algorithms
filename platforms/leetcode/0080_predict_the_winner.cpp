#include "../../template.hpp"

int rec(const vi& arr, const int i, const int j, const int left, const int right, const int p) {
    if (i > j) {
        return p == 0 ? left >= right : right > left;
    }
    if (p == 0) {
        return
            not rec(arr, i + 1, j, left + arr[i - 1], right, 1 - p) or
            not rec(arr, i, j - 1, left + arr[j - 1], right, 1 - p);
    }
    return
        not rec(arr, i + 1, j, left, right + arr[i - 1], 1 - p) or
        not rec(arr, i, j - 1, left, right + arr[j - 1], 1 - p);
}

int rec(const vi& arr) {
    if (arr.size() == 1) return 1;
    return rec(arr, 1, arr.size(), 0, 0, 0);
}

int rec2(const vi& arr, const int i, const int j, const int p) {
    if (i > j) {
        return 0;
    }
    if (p == 0) {
        return max(
            rec2(arr, i + 1, j, 1 - p) + arr[i - 1],
            rec2(arr, i, j - 1, 1 - p) + arr[j - 1]);
    }
    return min(
        rec2(arr, i + 1, j, 1 - p) - arr[i - 1],
        rec2(arr, i, j - 1, 1 - p) - arr[j - 1]);
}

int rec2(const vi& arr) {
    if (arr.size() == 1) return 1;
    return rec2(arr, 1, arr.size(), 0) >= 0;
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvvi dp(n + 2, vvi(n + 1, vi(2)));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            for (int p : {1, 0}) {
                if (i > j) {
                    dp[i][j][p] = 0;
                }
                else if (p == 0) {
                    dp[i][j][p] = max(
                        dp[i + 1][j][1 - p]+arr[i - 1],
                        dp[i][j - 1][1 - p]+arr[j - 1]);
                }
                else {
                    dp[i][j][p] = min(
                        dp[i + 1][j][1 - p]-arr[i - 1],
                        dp[i][j - 1][1 - p]-arr[j - 1]);
                }
            }
        }
    }
    return dp[1][n][0] >= 0;
}

int tab2(const vi& arr) {
    const int n = arr.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else dp[i][j] = max(arr[i - 1] - dp[i + 1][j], arr[j - 1] - dp[i][j - 1]);
        }
    }
    return dp[1][n] >= 0;
}

int main() { TimeMeasure _; __x();
    cout << rec({1,5,2}) << endl; // 0
    cout << rec({1,5,233,7}) << endl; // 1
    cout << rec({0}) << endl; // 1
    cout << rec({1,1,1}) << endl; // 1
    cout << rec({1,5,2,4,6}) << endl; // 1
    cout << endl;
    cout << rec2({1,5,2}) << endl; // 0
    cout << rec2({1,5,233,7}) << endl; // 1
    cout << rec2({0}) << endl; // 1
    cout << rec2({1,1,1}) << endl; // 1
    cout << rec2({1,5,2,4,6}) << endl; // 1
    cout << endl;
    cout << tab({1,5,2}) << endl; // 0
    cout << tab({1,5,233,7}) << endl; // 1
    cout << tab({0}) << endl; // 1
    cout << tab({1,1,1}) << endl; // 1
    cout << tab({1,5,2,4,6}) << endl; // 1
    cout << endl;
    cout << tab2({1,5,2}) << endl; // 0
    cout << tab2({1,5,233,7}) << endl; // 1
    cout << tab2({0}) << endl; // 1
    cout << tab2({1,1,1}) << endl; // 1
    cout << tab2({1,5,2,4,6}) << endl; // 1
}
