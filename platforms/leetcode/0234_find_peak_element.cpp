#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    if (n == 1) return 0;
    if (n == 2) {
        if (arr[0] == arr[1]) return 0;
        if (arr[0] > arr[1]) return 0;
        return 1;
    }
    if (arr[0] > arr[1]) return 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
            return i;
        }
    }
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    return 0;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,2,3,1}) << endl; // 2
    cout << sol({1,2,1,3,5,6,4}) << endl; // 5
    cout << sol({3,2,1}) << endl; // 0
    cout << sol({1,2,3}) << endl; // 2
}
