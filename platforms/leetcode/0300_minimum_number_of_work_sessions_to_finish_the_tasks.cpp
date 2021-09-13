#include "../../template.hpp"

int sol(const vector<int>& arr, const int sessionTime) {
    const int n = arr.size();
    static constexpr int SIZE = 1 << 15;
    array<int, SIZE> sums{};
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                sums[i] += arr[j];
            }
        }
    }
    array<int, SIZE> dp{};
    for (int i = 1; i < (1 << n); ++i) {
        dp[i] = INF;
        for (int j = i; j > 0; j = (j - 1) & i) {
            if (sums[j] <= sessionTime) {
                dp[i] = min(dp[i], dp[i ^ j] + 1);
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3}, 3) << endl; // 2
    cout << sol({3,1,3,1,1}, 8) << endl; // 2
    cout << sol({1,2,3,4,5}, 15) << endl; // 1
    cout << sol({2}, 3) << endl; // 1
    cout << sol({3,9}, 10) << endl; // 2
    cout << sol({9,6,9}, 14) << endl; // 3
    cout << sol({7,4,3,8,10}, 12) << endl; // 3
    cout << sol({9,8,8,4,6}, 14) << endl; // 3
    cout << sol({1,5,7,10,3,8,4,2,6,2}, 10) << endl; // 5
}
