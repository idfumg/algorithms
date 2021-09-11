#include "../../template.hpp"

int sol(vi nums, int k) {
    unordered_map<int, int> sums = {{0, 1}};
    int n = nums.size();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sums.count(sum - k)) ans += sums[sum - k];
        ++sums[sum];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,1,1}, 2) << endl; // 2
    cout << sol({1,2,3}, 3) << endl; // 2
    cout << sol({1,2,1,2,1}, 3) << endl; // 4
    cout << sol({1}, 0) << endl; // 0
}
