#include "../../template.hpp"

int sol(const vi& arr, const int target) {
    const int n = arr.size();
    ll ans = 0;
    ll current = 0;
    for (int i = 0; i < n and current < target; ++i) {
        for (; arr[i] > current + 1 and current < target; current += current + 1) {
            ++ans;
        }
        if (arr[i] <= current + 1) {
            current += arr[i];
        }
    }
    for (; current < target; current += current + 1) {
        ++ans;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,3}, 6) << endl; // 1
    cout << sol({1,5,10}, 20) << endl; // 2
    cout << sol({1,2,2}, 5) << endl; // 0
    cout << sol({1,2,31,33}, 2147483647) << endl; // 28
    cout << sol({1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94}, 20) << endl; // 1
}
