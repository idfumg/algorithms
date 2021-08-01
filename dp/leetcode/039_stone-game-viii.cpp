#include "../../template.hpp"

// int rec(vi& arr, int n, int player, int left, int right, int taken, int acc) {
//     if (taken < 2 and n < arr.size()) {
//         if (player == 0) return rec(arr, n + 1, player, left + arr[n], right, taken + 1, acc + arr[n]);
//         else return rec(arr, n + 1, player, left, right + arr[n], taken + 1, acc + arr[n]);
//     }
//     if (n > arr.size() - 1) {
//         return left - right;
//     }
//     if (player == 0) {
//         return max(
//             rec(arr, n, 1 - player, left, right + acc, 1, acc),
//             rec(arr, n + 1, player, left + arr[n], right, taken + 1, acc + arr[n]));
//     }
//     return min(
//         rec(arr, n, 1 - player, left + acc, right, 1, acc),
//         rec(arr, n + 1, player, left, right + arr[n], taken + 1, acc + arr[n]));
// }

// int rec(vi& arr) {
//     return rec(arr, 0, 0, 0, 0, 0, 0);
// }

// int rec(vi& arr, int n, int player, int taken, int acc) {
//     if (taken < 2 and n < arr.size()) {
//         if (player == 0) return rec(arr, n + 1, player, taken + 1, acc + arr[n]) + arr[n];
//         else return rec(arr, n + 1, player, taken + 1, acc + arr[n]) - arr[n];
//     }
//     if (n > arr.size() - 1) {
//         return 0;
//     }
//     if (player == 0) {
//         return max(
//             rec(arr, n, 1 - player, 1, acc) - acc,
//             rec(arr, n + 1, player, taken + 1, acc + arr[n]) + arr[n]);
//     }
//     return min(
//         rec(arr, n, 1 - player, 1, acc) + acc,
//         rec(arr, n + 1, player, taken + 1, acc + arr[n]) - arr[n]);
// }

// int rec(vi arr) {
//     return rec(arr, 0, 0, 0, 0);
// }

// int rec(vi& arr, vi& prefix, int n, int player, int taken, vvvi& dp) {
//     if (taken < 2 and n < arr.size()) {
//         if (player == 0) return dp[n][player][taken] = rec(arr, prefix, n + 1, player, taken + 1,dp)+ arr[n];
//         else return dp[n][player][taken] = rec(arr, prefix, n + 1, player, taken + 1,dp) - arr[n];
//     }
//     if (n > arr.size() - 1) {
//         return 0;
//     }
//     if (dp[n][player][taken] != INF) return dp[n][player][taken];
//     if (player == 0) {
//         return dp[n][player][taken] = max(
//             rec(arr, prefix, n, 1 - player, 1,dp) - prefix[n],
//             rec(arr, prefix, n + 1, player, taken + 1,dp) + arr[n]);
//     }
//     return dp[n][player][taken] = min(
//         rec(arr, prefix, n, 1 - player, 1,dp) + prefix[n],
//         rec(arr, prefix, n + 1, player, taken + 1,dp) - arr[n]);
// }

// int rec(vi arr) {
//     int n = arr.size();
//     vi prefix(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         prefix[i] = prefix[i - 1] + arr[i - 1];
//     }
//     vvvi dp(n + 1, vvi(2, vi(n + 1, INF)));
//     return rec(arr, prefix, 0, 0, 0, dp);
// }

int rec(const vi& arr, const vi& prefix, vi& dp, const int n) {
    if (n == arr.size()) return prefix[n];
    if (dp[n] != -INF) return dp[n];
    return dp[n] = max(
        prefix[n] - rec(arr, prefix, dp, n + 1),
        rec(arr, prefix, dp, n + 1));
}

int rec(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    vi dp(n + 1, -INF);
    return rec(arr, prefix, dp, 2);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    vi dp(n + 1, -INF);
    dp[n] = prefix[n];
    for (int i = n - 1; i >= 2; --i) {
        dp[i] = max(prefix[i] - dp[i + 1], dp[i + 1]);
    }
    return dp[2];
}

int tab_opt(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    vi dp(2, -INF);
    int idx = n & 1;
    dp[idx] = prefix[n];
    for (int i = n - 1; i >= 2; --i) {
        idx = i & 1;
        dp[idx] = max(prefix[i] - dp[1 - idx], dp[1 - idx]);
    }
    return dp[idx];
}

int main() { TimeMeasure _; __x();
    cout << rec({-1,2,-3,4,-5}) << endl; // 5
    cout << rec({7,-6,5,10,5,-2,-6}) << endl; // 13
    cout << rec({-10,-12}) << endl; // -22
    cout << rec({-39,-23,-43,-7,25,-36,-32,17,-42,-5,-11}) << endl; // 11
    cout << rec({25,-35,-37,4,34,43,16,-33,0,-17,-31,-42,-42,38,12,-5,-43,-10,-37,12}) << endl; // 38
    cout << rec({-53,-56,90,-74,-50,29,37,64,-31,-54,74,-80,-18,-69,-44,73,99,-47,-35,71,-55,-27,34,1,-66,-63,3,-34,33,91,-25,-40,-33,68,-34,-32,69,44,-54}) << endl; // 54
    cout << endl;
    cout << tab({-1,2,-3,4,-5}) << endl; // 5
    cout << tab({7,-6,5,10,5,-2,-6}) << endl; // 13
    cout << tab({-10,-12}) << endl; // -22
    cout << tab({-39,-23,-43,-7,25,-36,-32,17,-42,-5,-11}) << endl; // 11
    cout << tab({25,-35,-37,4,34,43,16,-33,0,-17,-31,-42,-42,38,12,-5,-43,-10,-37,12}) << endl; // 38
    cout << tab({-53,-56,90,-74,-50,29,37,64,-31,-54,74,-80,-18,-69,-44,73,99,-47,-35,71,-55,-27,34,1,-66,-63,3,-34,33,91,-25,-40,-33,68,-34,-32,69,44,-54}) << endl; // 54
    cout << endl;
    cout << tab_opt({-1,2,-3,4,-5}) << endl; // 5
    cout << tab_opt({7,-6,5,10,5,-2,-6}) << endl; // 13
    cout << tab_opt({-10,-12}) << endl; // -22
    cout << tab_opt({-39,-23,-43,-7,25,-36,-32,17,-42,-5,-11}) << endl; // 11
    cout << tab_opt({25,-35,-37,4,34,43,16,-33,0,-17,-31,-42,-42,38,12,-5,-43,-10,-37,12}) << endl; // 38
    cout << tab_opt({-53,-56,90,-74,-50,29,37,64,-31,-54,74,-80,-18,-69,-44,73,99,-47,-35,71,-55,-27,34,1,-66,-63,3,-34,33,91,-25,-40,-33,68,-34,-32,69,44,-54}) << endl; // 54
}
