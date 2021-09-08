#include "../../template.hpp"

int sol(vi arr) {
    const int n = arr.size();
    sort(arr.begin(), arr.end());
    return (arr[n - 1] * arr[n - 2]) - (arr[0] * arr[1]);
}

int main() { TimeMeasure _; //__x();
    cout << sol({5,6,2,7,4}) << endl; // 34
    cout << sol({4,2,5,9,7,4,8}) << endl; // 64
}
