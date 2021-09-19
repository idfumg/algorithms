#include "../../template.hpp"

i32 sol(vector<i32> nums) {
    i32 zeros = 0, window_size = 0, n = nums.size(), ans = 0, k = 1;
    for (i32 i = 0; i < n; ++i) {
        if (nums[i] == 0) ++zeros;
        ++window_size;
        while (zeros > k) {
            if (nums[i - window_size + 1] == 0) --zeros;
            --window_size;
        }
        ans = max(ans, window_size);
    }
    return ans;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({1,0,1,1,0}) << endl; // 4
    cout << sol({1,0,1,1,0,1}) << endl; // 4
}
