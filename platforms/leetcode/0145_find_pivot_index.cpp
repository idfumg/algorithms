#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        const int left = prefix[i - 1];
        const int right = prefix[n] - prefix[i];
        if (left == right) {
            return i - 1;
        }
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,7,3,6,5,6}) << endl; // 3
    cout << sol({1,2,3}) << endl; // -1
    cout << sol({2,1,-1}) << endl; // 0
}
