#include "../../template.hpp"

int sol(vi values, int k) {
    unordered_map<int, int> sums = {{0, -1}};
    int n = values.size();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += values[i];
        if (sums.count(sum - k)) ans = max(ans, i - sums[sum - k]);
        sums.insert({sum, i});
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,-1,5,-2,3}, 3) << endl; // 4
    cout << sol({-2,-1,2,1}, 1) << endl; // 2
}
