#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    vi dp1(n), dp2(n);
    dp1[0] = dp2[n - 1] = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) dp1[i] = 1;
        else dp1[i] = dp1[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] <= arr[i + 1]) dp2[i] = 1;
        else dp2[i] = dp2[i + 1] + 1;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,1,4,7,3,2,5}) << endl; // 5
    cout << tab({2,2,2}) << endl; // 0
    cout << tab({2,3}) << endl; // 0
}
