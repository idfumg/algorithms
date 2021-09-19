#include "../../template.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
//const i32 INF = 1000000000 + 7;
const i32 fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();

i32 sol(vector<i32> nums) {
    i32 n = nums.size(), window_size = 0, ans = 0, k = 2;
    unordered_map<i32, i32> types;
    for (i32 i = 0; i < n; ++i) {
        ++types[nums[i]];
        ++window_size;
        while (types.size() > k) {
            --types[nums[i - window_size + 1]];
            if (types[nums[i - window_size + 1]] == 0) {
                types.erase(nums[i - window_size + 1]);
            }
            --window_size;
        }
        ans = max(ans, window_size);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << sol({1,2,1}) << endl; // 3
    cout << sol({0,1,2,2}) << endl; // 3
    cout << sol({1,2,3,2,2}) << endl; // 4
    cout << sol({3,3,3,1,2,1,1,2,3,3,4}) << endl; // 5
}
