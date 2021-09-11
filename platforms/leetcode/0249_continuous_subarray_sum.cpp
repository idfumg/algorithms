#include "../../template.hpp"

int sol(vi nums, int k) {
    int n = nums.size();
    unordered_map<int, int> sums = {{0, -1}};
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        sum %= k;
        if (sums.count(sum) and i - sums[sum] > 1) {
            return 1;
        }
        sums.insert({sum, i});
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol({23,2,4,6,7}, 6) << endl; // 1
    cout << sol({23,2,6,4,7}, 6) << endl; // 1
    cout << sol({23,2,6,4,7}, 13) << endl; // 0
    cout << sol({0}, 1) << endl; // 0
    cout << sol({5,0,0,0}, 3) << endl; // 1
}
