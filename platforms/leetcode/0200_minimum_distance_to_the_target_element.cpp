#include "../../template.hpp"

int sol(const vi& arr, const int target, const int start) {
    const int n = arr.size();
    int ans = 1000000007;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            ans = min(ans, abs(i - start));
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,2,3,4,5}, 5, 3) << endl; // 1
    cout << sol({1}, 1, 0) << endl; // 0
    cout << sol({1,1,1,1,1,1,1,1,1,1}, 1, 0) << endl; // 0
}
