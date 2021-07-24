#include "../../template.hpp"

vi naive(vi arr) {
    int n = arr.size();
    vi ans;
    for (int i = 1; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    return ans;
}

vi tab(vi arr) {
    int n = arr.size();
    vvvi dp(n + 1, vvi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = {arr[i - 1]};
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = k; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                for (int sum : dp[k - 1][j]) {
                    dp[k][i].push_back(sum + arr[i - 1]);
                }
            }
        }
    }
    vi ans;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int sum : dp[k][i]) {
                ans.push_back(sum);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3};
    vi arr2 = {2, 3, 4, 5, 6};
    vi arr3 = {20, 30, 50};

    cout << naive(arr1) << '\n';
    cout << naive(arr2) << '\n';
    cout << naive(arr3) << '\n';
    cout << '\n';
    cout << tab(arr1) << '\n';
    cout << tab(arr2) << '\n';
    cout << tab(arr3) << '\n';
}
