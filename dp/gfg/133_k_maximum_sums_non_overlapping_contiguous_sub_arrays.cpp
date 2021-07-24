#include "../../template.hpp"

vi tab(vi arr, int k) {
    int n = arr.size();
    vi ans;

    while (k--) {
        vi dp(n);
        vi prev(n, -1);
        int maxi = arr[0];
        int idx = 0;
        dp[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] + arr[i] > arr[i]) {
                dp[i] = dp[i - 1] + arr[i];
                prev[i] = i - 1;
            }
            else {
                dp[i] = arr[i];
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                idx = i;
            }
        }
        ans.push_back(maxi);
        for (int at = idx; at != -1; at = prev[at]) {
            arr[at] = -INF;
        }
    }

    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2}; int k1 = 3;
    vi arr2 = {5, 1, 2, -6, 2, -1, 3, 1}; int k2 = 2;

    cout << tab(arr1, k1) << endl; // 8 6 -1
    cout << tab(arr2, k2) << endl; // 8 5
}
