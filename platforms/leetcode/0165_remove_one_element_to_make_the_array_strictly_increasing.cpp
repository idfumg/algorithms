#include "../../template.hpp"

int sol(vi nums, int n, int k) {
    if (k < 0) return 0;
    if (n <= 1) return 1;
    if (n == 2) return nums[n - 1] > nums[n - 2] or k > 0;
    if (nums[n - 1] <= nums[n - 2]) return (nums[n - 2] < nums[n] and sol(nums, n - 1, k - 1)) or (nums[n - 1] > nums[n - 3] and sol(nums, n - 2, k - 1));
    return sol(nums, n - 1, k);
}

int sol(vi nums) {
    int n = nums.size();
    if (n == 1) return 1;
    if (nums[n - 1] <= nums[n - 2]) return sol(nums, n - 1, 0) or (nums[n - 1] > nums[n - 3] and sol(nums, n - 2, 0));
    return sol(nums, n - 1, 1);
}

int sol2(vi nums) {
    int n = nums.size();
    vi dp(n, 1);
    dp[0] = 1;
    int max_length = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }
    return (n - max_length) <= 1;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,10,5,7}) << endl; // 1
    cout << sol({2,3,1,2}) << endl; // 0
    cout << sol({1,1,1}) << endl; // 0
    cout << sol({1,2,3}) << endl; // 1
    cout << sol({105,924,32,968}) << endl; // 1
    cout << sol({512,867,904,997,403}) << endl; // 1
    cout << sol({100,21,100}) << endl; // 1
    cout << sol({915,444,500}) << endl; // 1
    cout << endl;
    cout << sol2({1,2,10,5,7}) << endl; // 1
    cout << sol2({2,3,1,2}) << endl; // 0
    cout << sol2({1,1,1}) << endl; // 0
    cout << sol2({1,2,3}) << endl; // 1
    cout << sol2({105,924,32,968}) << endl; // 1
    cout << sol2({512,867,904,997,403}) << endl; // 1
    cout << sol2({100,21,100}) << endl; // 1
    cout << sol2({915,444,500}) << endl; // 1
}
