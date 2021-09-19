#include "../../template.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
//const i32 INF = 1000000000 + 7;
const i32 fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();

// i32 sol(vector<i32> nums, i32 k) {
//     i32 n = nums.size(), window_size = 0, ans = 0;

//     vector<i32> left(n, -1), right(n, n);
//     for (i32 i = 0; i < n - 1; ++i) {
//         left[i + 1] = nums[i] & 1 ? i : left[i];
//     }
//     for (i32 i = n - 1; i > 0; --i) {
//         right[i - 1] = nums[i] & 1 ? i : right[i];
//     }

//     deque<pair<i32, i32>> window;
//     for (i32 i = 0; i < n; ++i) {
//         if (nums[i] & 1) {
//             window.push_back({nums[i], i});
//             ++window_size;
//         }
//         if (window_size == k) {
//             i32 idx1 = window.front().second;
//             i32 idx2 = window.back().second;
//             ans += (idx1 - left[idx1]) * (right[idx2] - idx2);

//             window.pop_front();
//             --window_size;
//         }

//     }
//     return ans;
// }

i32 sol_(vector<i32>& nums, i32 k) {
    i32 n = nums.size(), ans = 0, window_size = 0, odds = 0;
    deque<i32> window;
    for (i32 i = 0; i < n; ++i) {
        window.push_back(nums[i]);
        ++window_size;
        odds += nums[i] & 1;

        while (odds > k) {
            if (window.front() & 1) --odds;
            window.pop_front();
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
    cout << sol({1,1,2,1,1}, 3) << endl; // 2
    cout << sol({2,4,6}, 1) << endl; // 0
    cout << sol({2,2,2,1,2,2,1,2,2,2}, 2) << endl; // 16
    cout << sol({91473,45388,24720,35841,29648,77363,86290,58032,53752,87188,34428,85343,19801,73201}, 4) << endl; // 6
}
