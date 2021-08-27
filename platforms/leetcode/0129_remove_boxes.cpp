#include "../../template.hpp"

// vvi compress(const vi& arr) {
//     vvi ans;
//     if (arr.empty()) return {};
//     ans.push_back({arr[0], 1});
//     for (int i = 1; i < arr.size(); ++i) {
//         if (ans.back()[0] == arr[i]) ++ans.back()[1];
//         else ans.push_back({arr[i], 1});
//     }
//     return ans;
// }

// vvi compress(const vvi& arr, const int left, const int right, const int k) {
//     vvi ans;
//     if (arr.empty()) return {};
//     for (int i = left; i <= right; ++i) {
//         if (i == k) continue;
//         else if (ans.empty()) ans.push_back(arr[i]);
//         else if (ans.back()[0] == arr[i][0]) ans.back()[1] += arr[i][1];
//         else ans.push_back(arr[i]);
//     }
//     return ans;
// }

// int rec(const vvi& arr, const int left, const int right) {
//     if (left > right) return 0;
//     if (left == right) return arr[left][1] * arr[left][1];
//     int ans = 0;
//     for (int k = left; k < right; ++k) {
//         const vvi values = compress(arr, left, right, k);
//         ans = max(ans, rec(values, 0, values.size() - 1) + arr[k][1] * arr[k][1]);
//     }
//     return ans;
// }

// int rec(const vi& arr) {
//     const vvi values = compress(arr);
//     return rec(values, 0, values.size() - 1);
// }

int rec(const vi& arr, const int i, const int j, const int k) {
    if (i > j) return 0;
    int ans = rec(arr, i + 1, j, 1) + k * k;
    for (int p = i + 1; p <= j; ++p) {
        if (arr[i] == arr[p]) ans = max(ans, rec(arr, i + 1, p - 1, 1) + rec(arr, p, j, k + 1));
    }
    return ans;
}

int rec(const vi& arr) {
    return rec(arr, 0, arr.size() - 1, 1);
}

array<array<array<int, 101>, 101>, 102> dp{};

int tab(const vi& arr) {
    const int n = arr.size();
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= n - 1; ++j) {
            for (int k = n; k >= 1; --k) {
                if (i > j) {
                    dp[i][j][k] = 0;
                    continue;
                }
                int ans = dp[i + 1][j][1] + k * k;
                for (int p = i + 1; p <= j; ++p) {
                    if (arr[i] == arr[p]) ans = max(ans, dp[i + 1][p - 1][1] + dp[p][j][k + 1]);
                }
                dp[i][j][k] = ans;
            }
        }
    }
    return dp[0][n - 1][1];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,3,2,2,2,3,4,3,1}) << endl; // 23
    cout << rec({1,1,1}) << endl; // 9
    cout << rec({1}) << endl; // 1
    cout << rec({1,2,3,4,5,6,7,8,9,10}) << endl; // 10
    //cout << rec({1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1}) << endl; // 10
    cout << endl;
    cout << tab({1,3,2,2,2,3,4,3,1}) << endl; // 23
    cout << tab({1,1,1}) << endl; // 9
    cout << tab({1}) << endl; // 1
    cout << tab({1,2,3,4,5,6,7,8,9,10}) << endl; // 10
    cout << tab({1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1}) << endl; // 10
}
