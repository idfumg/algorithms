#include "../../template.hpp"

int rec(vi arr, int n) {
    if (n <= 1) return 0;
    if (n == 2) return min(arr[n - 1], arr[n - 2]);
    return min(rec(arr, n - 2) + arr[n - 2],
               rec(arr, n - 1) + arr[n - 1]);
}

int rec(vi arr) {
    return rec(arr, arr.size());
}

int tab(vi arr) {
    int n = arr.size();
    vi dp(n + 1);
    dp[2] = min(arr[0], arr[1]);
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 2] + arr[i - 2],
                    dp[i - 1] + arr[i - 1]);
    }
    return dp[n];
}

int rec2(vi arr, int n, bool skipped) {
    if (n == 0) return 0;
    if (skipped) return rec2(arr, n - 1, false) + arr[n - 1];
    return min(rec2(arr, n - 1, false) + arr[n - 1], rec2(arr, n - 1, true));
}

int rec2(vi arr) {
    return rec2(arr, arr.size(), false);
}

int tab2(vi arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (int j : {0, 1}) {
            if (j == 1) dp[i][j] = dp[i - 1][0] + arr[i - 1];
            else dp[i][j] = min(dp[i - 1][0] + arr[i - 1], dp[i - 1][1]);
        }
    }
    return min(dp[n]);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 5, 7, 10}; // 12
    vi arr2 = {10}; // 0
    vi arr3 = {10, 30}; // 10
    vi arr4 = {10, 5, 2, 4, 8, 6, 7, 10}; // 22
    vi arr5 = {467, 334, 500, 169, 724, 478, 358, 962, 464, 705, 145, 281}; // 1948

    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << rec(arr5) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
    cout << endl;
    cout << rec2(arr1) << endl;
    cout << rec2(arr2) << endl;
    cout << rec2(arr3) << endl;
    cout << rec2(arr4) << endl;
    cout << rec2(arr5) << endl;
    cout << endl;
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
    cout << tab2(arr4) << endl;
    cout << tab2(arr5) << endl;
}
