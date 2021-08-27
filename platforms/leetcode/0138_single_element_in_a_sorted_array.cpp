#include "../../template.hpp"

int sol(vi arr) {
    const int n = arr.size();
    if (n == 1) return arr[0];
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i += 2) {
        if (arr[i] != arr[i - 1]) {
            return arr[i - 1];
        }
    }
    return arr.back() != arr[n - 2] ? arr.back() : -1;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,1,2,3,3,4,4,8,8}) << endl; // 2
    cout << sol({3,3,7,7,10,11,11}) << endl; // 10
    cout << sol({1,1,2}) << endl; // 2
}
