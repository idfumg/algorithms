#include "../../template.hpp"

int sol(const vi& arr, const int from, const int to) {
    const int n = arr.size();
    int ans = 1000000007;
    int current = 0;
    for (int i = from; i % n != to; ++i) {
        current += arr[i % n];
    }
    ans = min(ans, current);
    current = 0;
    for (int i = to; i % n != from; ++i) {
        current += arr[i % n];
    }
    ans = min(ans, current);
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,4}, 0, 1) << endl; // 1
    cout << sol({1,2,3,4}, 0, 2) << endl; // 3
    cout << sol({1,2,3,4}, 0, 3) << endl; // 4
    cout << sol({7,10,1,12,11,14,5,0}, 7, 2) << endl; // 4
}
