#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    unordered_map<int, int> sums = {{0, -1}};
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i] == 0 ? -1 : 1;
        if (sums.count(sum)) {
            ans = max(ans, i - sums[sum]);
        }
        sums.insert({sum, i});
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({0,1}) << endl; // 2
    cout << sol({0,1,0}) << endl; // 2
    cout << sol({0,1,0,0,1}) << endl; // 4
    cout << sol({0,1,1,1,1,1,1,0}) << endl; // 2
    cout << sol({0,0,1,0,0,0,1,1}) << endl; // 6
    cout << sol({0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1}) << endl; // 68
}
