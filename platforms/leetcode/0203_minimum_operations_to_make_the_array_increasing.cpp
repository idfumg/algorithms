#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    if (n == 1) return 0;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) {
            ans += arr[i - 1] - arr[i] + 1;
            arr[i] = arr[i - 1] + 1;
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,1,1}) << endl; // 3
    cout << sol({1,5,2,4,1}) << endl; // 14
    cout << sol({8}) << endl; // 0
}
