#include "../../template.hpp"

int sol(vi nums, int k) {
    unordered_map<int, int> sums = {{0, 1}};
    int sum = 0;
    int ans = 0;
    for (int num : nums) {
        sum = (sum % k + num % k + k) % k;
        if (sums.count(sum)) ans += sums[sum];
        ++sums[sum];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({4,5,0,-2,-3,1}, 5) << endl; // 7
    cout << sol({5}, 9) << endl; // 0
    cout << sol({7,4,-10}, 5) << endl; // 1
}
