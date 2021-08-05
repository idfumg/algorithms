#include "../../template.hpp"

// 1 2 3 4 5 subarray length 1
// 1 2 X X X subarray length 2
// X 2 3 X X subarray length 2
// X X 3 4 X subarray length 2
// X X X 4 5 subarray length 2
// 1 2 3 X X subarray length 3
// X 2 3 4 X subarray length 3
// X X 3 4 5 subarray length 3
// 1 2 3 4 X subarray length 4
// X 2 3 4 5 subarray length 4
// 1 2 3 4 5 subarray length 5

// 5 8 9 8 5 total times each index was added, k = (i + 1) * (n - i)
// 3 4 5 4 3 total times in odd length array with (k + 1) / 2
// 2 4 4 4 2 total times in even length array with k / 2s

int naive(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if ((j - i + 1) & 1) {
                ans += prefix[j] - prefix[i - 1];
            }
        }
    }
    return ans;
}

int tab(const vi& arr) {
    const int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((i + 1) * (n - i) + 1) / 2 * arr[i];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << naive({1,4,2,5,3}) << endl; // 58
    cout << naive({1,2}) << endl; // 3
    cout << naive({10,11,12}) << endl; // 66
    cout << endl;
    cout << tab({1,4,2,5,3}) << endl; // 58
    cout << tab({1,2}) << endl; // 3
    cout << tab({10,11,12}) << endl; // 66
}
