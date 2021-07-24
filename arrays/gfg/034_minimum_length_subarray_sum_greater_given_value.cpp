#include "../../template.hpp"

int tab2(vi arr, int target) {
    int n = arr.size();
    int window = 0;
    int windowSize = 0;
    int windowStart = 0;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        window += arr[i];
        ++windowSize;
        while (window > target) {
            if (windowSize < ans) {
                ans = windowSize;
            }
            window -= arr[windowStart++];
            --windowSize;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << tab2({1, 4, 45, 6, 0, 19}, 51) << '\n'; // 3
    cout << tab2({1, 10, 5, 2, 7}, 9) << '\n'; // 1
    cout << tab2({1, 1, 5, 2, 7, 10}, 9) << '\n'; // 1
    cout << tab2({1, 1, 10}, 9) << '\n'; // 1
    cout << tab2({10, 1, 2}, 9) << '\n'; // 1
    cout << tab2({1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, 280) << '\n'; // 4
    cout << tab2({1, 2, 4}, 8) << '\n'; // -1
}
