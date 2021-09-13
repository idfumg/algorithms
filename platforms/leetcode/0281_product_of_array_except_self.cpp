#include "../../template.hpp"

vi sol(const vi& arr) {
    const int n = arr.size();
    vi left(n + 1);
    left[0] = 1;
    for (int i = 1; i <= n; ++i) {
        left[i] = left[i - 1] * arr[i - 1];
    }
    vi right(n + 2);
    right[n + 1] = 1;
    for (int i = n; i >= 1; --i) {
        right[i] = right[i + 1] * arr[i - 1];
    }
    vi ans(n);
    for (int i = 1; i <= n; ++i) {
        ans[i - 1] = left[i - 1] * right[i + 1];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,4}) << endl; // 24,12,8,6
    cout << sol({-1,1,0,-3,3}) << endl; // 0,0,9,0,0
}
