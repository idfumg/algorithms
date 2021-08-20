#include "../../template.hpp"

vi sol(const vi& arr, const int target) {
    const int n = arr.size();
    unordered_map<int, int> sums;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum == target) {
            return {0, i};
        }
        if (sums.count(sum - target)) {
            return {sums[sum - target] + 1, i};
        }
        sums[sum] = i;
    }
    return {};
}

int main() { TimeMeasure _; __x();
    cout << sol({1,4,20,3,10,5}, 33) << endl; // 2,4
    cout << sol({10,2,-2,-20,10}, -10) << endl; // 0,3
    cout << sol({-10,0,2,-2,-20,10}, 20) << endl; // []
}
