#include "../../template.hpp"

int sol(vvi nums) {
    sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    int ans = 0;
    set<int> window;
    for (auto& num : nums) {
        if (window.upper_bound(num[1]) != window.end()) ++ans;
        window.insert(num[1]);
    }
    return ans;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({{5,5},{6,3},{3,6}}) << endl; // 0
    cout << sol({{2,2},{3,3}}) << endl; // 1
    cout << sol({{1,5},{10,4},{4,3}}) << endl;  // 1
}
