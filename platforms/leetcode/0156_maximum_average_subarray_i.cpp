#include "../../template.hpp"

double sol(const vi& arr, const int k) {
    const int n = arr.size();
    double ans = -INF;
    int window = 0;
    int window_size = 0;
    for (int i = 0; i < n; ++i) {
        window += arr[i];
        ++window_size;
        if (window_size == k) {
            ans = max(ans, (double)window / window_size);
            window -= arr[i - window_size + 1];
            --window_size;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,12,-5,-6,50,3}, 4) << endl; // 12.75000
    cout << sol({5}, 1) << endl; // 5.00000
    cout << sol({-1}, 1) << endl; // -1.00000
}
