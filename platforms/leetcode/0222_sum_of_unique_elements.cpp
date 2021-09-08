#include "../../template.hpp"

int sol(const vi& arr) {
    array<int, 101> nums{};
    for (const int value : arr) {
        ++nums[value];
    }
    int ans = 0;
    for (int i = 0 ; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            ans += i;
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,2,3,2}) << endl; // 4
    cout << sol({1,1,1,1,1}) << endl; // 0
    cout << sol({1,2,3,4,5}) << endl; // 15
}
