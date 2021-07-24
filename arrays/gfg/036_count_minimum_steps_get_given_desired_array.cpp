#include "../../template.hpp"

int CountMinSteps(vi arr) {
    int n = arr.size();
    int minValue = INF;
    int notZerosCount = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            if (minValue > arr[i]) {
                minValue = arr[i];
            }
            ++notZerosCount;
        }
    }
    if (minValue & 1 and minValue > 1) {
        --minValue;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > minValue) {
            ans += arr[i] - minValue;
        }
    }
    int doubleOps = log2(minValue);
    return ans + notZerosCount + doubleOps;
}

int main() { TimeMeasure _;
    cout << CountMinSteps({2, 3}) << '\n'; // 4
    cout << CountMinSteps({2, 1}) << '\n'; // 3
    cout << CountMinSteps({16, 16, 16}) << '\n'; // 7
    cout << CountMinSteps({2, 5}) << '\n'; // 6
    cout << CountMinSteps({5, 3}) << '\n'; // 7
    cout << CountMinSteps({5, 1}) << '\n'; // 6
    cout << CountMinSteps({5, 0}) << '\n'; // 4
}
