#include "../../template.hpp"

int sol(vector<i32>& nums, i32 i, i32 j, vector<vector<i32>>& dp) {
    if (j - i < 2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    i32 ans = INF;
    for (i32 k = i + 1; k < j; ++k) {
        ans = min(ans, sol(nums, i, k, dp) + sol(nums, k, j, dp) + nums[j] - nums[i]);
    }
    return dp[i][j] = ans;
}

int sol(vector<i32> nums, int length) {
    if (nums.size() < 1) return 0;
    if (nums.front() != 0) nums.insert(nums.begin(), 0);
    if (nums.back() != length) nums.push_back(length);
    sort(nums.begin(), nums.end());
    i32 n = nums.size();
    vector<vector<i32>> dp(n, vector<i32>(n, -1));
    return sol(nums, 0, n - 1, dp);
}

int tab(vector<i32> nums, i32 length) {
    if (nums.size() < 1) return 0;
    if (nums.front() != 0) nums.insert(nums.begin(), 0);
    if (nums.back() != length) nums.push_back(length);
    sort(nums.begin(), nums.end());
    i32 n = nums.size();
    vector<vector<i32>> dp(n, vector<i32>(n, INF));
    for (i32 i = n - 1; i >= 0; --i) {
        for (i32 j = 0; j <= n - 1; ++j) {
            if (j - i < 2 or i >= j) {
                dp[i][j] = 0;
            }
            else {
                i32 ans = INF;
                for (i32 k = i + 1; k < j; ++k) {
                    ans = min(ans, dp[i][k] + dp[k][j] + nums[j] - nums[i]);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[0][n - 1];
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({1,3,4,5}, 7) << endl; // 16
    cout << sol({5,6,1,4,2}, 9) << endl; // 22
    cout << sol({1}, 2) << endl; // 2
    cout << endl;
    cout << tab({1,3,4,5}, 7) << endl; // 16
    cout << tab({5,6,1,4,2}, 9) << endl; // 22
    cout << tab({1}, 2) << endl; // 2
}
