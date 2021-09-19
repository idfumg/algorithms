#include "../../template.hpp"

int sol(const vector<int>& nums) {
    int n = nums.size();
    int mod = 1e9 + 7;
    vector<vector<int64_t>> dp(2, vector<int64_t>(n + 1)); // dp[0][i] - the first odd times, dp[1][i] - even times
    dp[0][1] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = (dp[1][i - 1] + 1) % mod;
        dp[1][i] = (2 * dp[0][i] + 1 - dp[0][nums[i - 1] + 1] + mod) % mod;
    }
    return dp[0][n];
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({0,0}) << endl; // 2
    cout << sol({0,0,2}) << endl; // 6
    cout << sol({0,1,2,0}) << endl; // 6
    cout << sol({0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48}) << endl; // 86417750
}
