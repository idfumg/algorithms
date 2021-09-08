#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                x ^= arr[j];
            }
        }
        ans += x;
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,3}) << endl; // 6
    cout << sol({5,1,6}) << endl; // 28
    cout << sol({3,4,5,6,7,8}) << endl; // 480
    cout << sol({2,4,4}) << endl; // 24
}
