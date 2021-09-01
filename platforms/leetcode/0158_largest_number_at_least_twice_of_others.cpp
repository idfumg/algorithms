#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    int prevmaxi = 0;
    int maxi = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (maxi < arr[i]) {
            maxi = arr[i];
            idx = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (prevmaxi < arr[i] and arr[i] != maxi) {
            prevmaxi = arr[i];
        }
    }
    return 2 * prevmaxi <= maxi ? idx : -1;
}

int main() { TimeMeasure _; __x();
    cout << sol({3,6,1,0}) << endl; // 1
    cout << sol({1,2,3,4}) << endl; // -1
    cout << sol({1}) << endl; // 0
    cout << sol({0,0,3,2}) << endl; // -1
}
