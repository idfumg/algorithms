#include "../../template.hpp"

int rec(vi arr, int i, int n) {
    if (i >= n) return i == n;
    int count = 0;
    for (int j = 1; j <= arr[i - 1]; ++j) {
        count += rec(arr, i + j, n);
    }
    return count;
}

vi rec(vi arr) {
    vi ans(arr.size());
    for (int i = 0; i < arr.size() - 1; ++i) {
        int count = rec(arr, i + 1, arr.size());
        ans[i] = count == 0 ? -1 : count;
    }
    return ans;
}

vi tab(vi arr) {
    int n = arr.size();
    vi dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 1; j <= arr[i]; ++j) {
            if (i + j < n) {
                dp[i] += dp[i + j];
            }
        }
    }
    for (int& v : dp) {
        if (v == 0) v = -1;
    }
    dp[n - 1] = 0;
    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << rec(arr1) << endl; // 2 1 -1 0
    cout << rec(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << endl;
    cout << tab(arr1) << endl; // 2 1 -1 0
    cout << tab(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
}
