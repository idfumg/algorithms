#include "../../template.hpp"

int ans(const vi& arr, const int k) {
    if (k == 0) return 0;
    const int n = arr.size();
    int ans = 0;
    int window = 1;
    int window_size = 0;
    for (int i = 0; i < n; ++i) {
        window *= arr[i];
        ++window_size;
        while (window_size > 0 and window >= k) {
            window /= arr[i - window_size + 1];
            --window_size;
        }
        if (window < k) {
            ans += window_size;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << ans({10,5,2,6}, 100) << endl; // 8
    cout << ans({1,2,3}, 0) << endl; // 0
    cout << ans({1,1,1}, 2) << endl; // 6
    cout << ans({1,1,1}, 1) << endl; // 0
}
