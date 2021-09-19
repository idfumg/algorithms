#include "../../template.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
//const i32 INF = 1000000000 + 7;
const i32 fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();

i32 sol_(vector<i32>& nums, i32 k) {
    i32 n = nums.size(), ans = 0, window_size = 0;
    unordered_map<i32, i32> window;
    for (i32 i = 0; i < n; ++i) {
        ++window[nums[i]];
        ++window_size;
        while (window.size() > k) {
            if (--window[nums[i - window_size + 1]] == 0) {
                window.erase(nums[i - window_size + 1]);
            }
            --window_size;
        }
        ans += window_size;
    }
    return ans;
}

i32 sol(vector<i32> nums, i32 k) {
    return sol_(nums, k) - sol_(nums, k - 1);
}

int main() { TimeMeasure _;
    cout << sol({1,2,1,2,3}, 2) << endl; // 7
    cout << sol({1,2,1,3,4}, 3) << endl; // 3
}
