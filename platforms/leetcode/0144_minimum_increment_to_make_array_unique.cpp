#include "../../template.hpp"

int sol(vi arr) {
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) {
            const int d = arr[i - 1] - arr[i] + 1;
            ans += d;
            arr[i] += d;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,2}) << endl; // 1
    cout << sol({3,2,1,2,1,7}) << endl; // 6
}
