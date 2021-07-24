#include "../../template.hpp"

// int rec(vi& used, const int N, const int n, const int target) {
//     if (n == 0) return 0;
//     if (not used[n]) {
//         if (n >= target) return 1;
//         used[n] = 1;
//         if (!rec(used, N, N, target - n)) {
//             used[n] = 0;
//             return 1;
//         }
//         used[n] = 0;
//     }
//     return rec(used, N, n - 1, target);
// }

// int rec(const int N, const int target) {
//     if (N * (N + 1) / 2 < target) return false;
//     vi used(N + 1);
//     return rec(used, N, N, target);
// }

// int rec(vi& used, const int target) {
//     int N = used.size() - 1;
//     for (int n = N; n >= 1; --n) {
//         if (not used[n]) {
//             if (n >= target) return 1;
//             used[n] = 1;
//             if (!rec(used, target - n)) {
//                 used[n] = 0;
//                 return 1;
//             }
//             used[n] = 0;
//         }
//     }
//     return 0;
// }

// int rec(const int N, const int target) {
//     if (N * (N + 1) / 2 < target) return false;
//     vi used(N + 1);
//     return rec(used, target);
// }

int rec(const int N, const int target, int mask, vector<int>& dp) {
    if (dp[mask] != -1) return 1;
    for (int n = N; n >= 1; --n) {
        if (mask & (1 << n)) continue;
        if (n >= target) return 1;
        mask |= (1 << n);
        if (not rec(N, target - n, mask, dp)) {
            mask &= ~(1 << n);
            dp[mask] = 1;
            return 1;
        }
        mask &= ~(1 << n);
    }
    return 0;
}

int rec(const int N, const int target) {
    if (N * (N + 1) / 2 < target) return false;
    if (N >= target) return true;
    vector<int> dp(1 << (N + 1), -1);
    int mask = 0;
    return rec(N, target, mask, dp);
}

int main() { TimeMeasure _; __x();
    cout << rec(10, 11) << endl; // 0
    cout << rec(10, 0) << endl; // 1
    cout << rec(10, 1) << endl; // 1
    cout << rec(10, 40) << endl; // 0
    cout << rec(4, 6) << endl; // 1
}
