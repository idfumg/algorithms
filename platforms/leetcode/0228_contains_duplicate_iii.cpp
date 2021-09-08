#include "../../template.hpp"

int sol(vi nums, int k, int target) {
    int n = nums.size();
    if (n < 2) return 0;
    multiset<ll> window = {nums[0]};
    for (int i = 1; i < n; ++i) {
        window.insert(nums[i]);

        if (window.size() > k + 1) {
            window.erase(window.find(nums[i - window.size() + 1]));
        }

        const auto it = window.find(nums[i]);
        if (it != window.begin() and abs(*it - *prev(it)) <= target) return 1;
        if (next(it) != window.end() and abs(*it - *next(it)) <= target) return 1;
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,1}, 3, 0) << endl; // 1
    cout << sol({1,0,1,1}, 1, 2) << endl; // 1
    cout << sol({1,5,9,1,5,9}, 2, 3) << endl; // 0
    cout << sol({0}, 0, 0) << endl; // 0
    cout << sol({1,2,2,3,4,5}, 3, 0) << endl; // 1
    cout << sol({1,2,2,3,1}, 3, 0) << endl; // 1
    cout << sol({1,2,5,6,7,2,4}, 4, 0) << endl; // 1
    cout << sol({-2147483648,2147483647}, 1, 1) << endl; // 0
    cout << sol({2147483646,2147483647}, 3, 3) << endl; // 1
    cout << sol({1,2}, 0, 1) << endl; // 0
    cout << sol({7,2,8}, 2, 1) << endl; // 1
    cout << sol({}, 0, 0) << endl; // 1
}
