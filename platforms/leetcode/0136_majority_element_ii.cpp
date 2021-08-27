#include "../../template.hpp"

vi sol(const vi& arr) {
    const int n = arr.size();
    unordered_map<int, int> count;
    si ans;
    for (int i = 0; i < n; ++i) {
        if (++count[arr[i]] > n / 3) {
            ans.insert(arr[i]);
        }
    }
    return vi(ans.begin(), ans.end());
}

int main() { TimeMeasure _; __x();
    cout << sol({3,2,3}) << endl; // 3
    cout << sol({1}) << endl; // 1
    cout << sol({1,2}) << endl; // 1,2
}
