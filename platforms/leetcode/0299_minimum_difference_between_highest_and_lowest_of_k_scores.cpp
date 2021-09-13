#include "../../template.hpp"

int sol(vi arr, const int k) {
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int ans = INF;

    for (int i = 0; i < n and i + k - 1 < n; ++i) {
        ans = min(ans, arr[i + k - 1] - arr[i]);
    }

    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({90}, 1) << endl; // 0
    cout << sol({9,4,1,7}, 2) << endl; // 2
    cout << sol({87063,61094,44530,21297,95857,93551,9918}, 6) << endl; // 74560
}
