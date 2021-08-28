#include "../../template.hpp"

int sol(const vi& arr, const int k) {
    const int n = arr.size();
    unordered_map<int, vi> m;
    for (int i = 0; i < n; ++i) {
        m[arr[i]].push_back(i);
    }
    for (const auto& [key, values] : m) {
        const int n = values.size();
        for (int i = 1; i < n; ++i) {
            if (values[i] - values[i - 1] <= k) {
                return 1;
            }
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,1}, 3) << endl; // 1
    cout << sol({1,0,1,1}, 1) << endl; // 1
    cout << sol({1,2,3,1,2,3}, 2) << endl; // 0
}
