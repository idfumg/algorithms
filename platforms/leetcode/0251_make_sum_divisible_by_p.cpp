#include "../../template.hpp"

int sol(const vi& arr, const int k) {
    const int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        sum %= k;
    }
    if (sum == 0) return 0;
    unordered_map<int, int> prev = {{0, -1}};
    int prefix = 0;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        prefix += arr[i];
        prefix %= k;
        prev[prefix] = i;
        int rem = (prefix - sum + k) % k;
        if (prev.count(rem)) {
            if (i - prev[rem] < n) {
                ans = min(ans, i - prev[rem]);
            }
        }
    }
    return ans == INF ? -1 : ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({3,1,4,2}, 6) << endl; // 1
    cout << sol({6,3,5,2}, 9) << endl; // 2
    cout << sol({1,2,3}, 3) << endl; // 0
    cout << sol({1,2,3}, 7) << endl; // -1
    cout << sol({1000000000,1000000000,1000000000}, 3) << endl; // 0
    cout << sol({26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3}, 26) << endl; // 3
}
