#include "../../template.hpp"

int tab(vi arr) {
    const int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0, j = n - i - 1; i < j; ++i, --j) {
        ans = max(ans, arr[j] + arr[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({3,5,2,3}) << endl; // 7
    cout << tab({3,5,4,2,4,6}) << endl; // 8
}
