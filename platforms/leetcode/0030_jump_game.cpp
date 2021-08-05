#include "../../template.hpp"

int rec(const vi& arr, int n) {
    if (n == arr.size()) return true;
    for (int k = 1; k <= arr[n - 1] and n + k <= arr.size(); ++k) {
        if (rec(arr, n + k)) {
            return true;
        }
    }
    return false;
}

int rec(const vi& arr) {
    return rec(arr, 1);
}

int tab(const vi& arr) {
    int n = arr.size();
    vi dp(n + 1);
    dp[n] = 1;
    for (int i = n; i >= 1; --i) {
        for (int k = 1; k <= arr[i - 1] and i + k <= arr.size(); ++k) {
            if (dp[i + k]) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[1];
}

int main() { TimeMeasure _; __x();
    cout << rec({2,3,1,1,4}) << endl; // 1
    cout << rec({3,2,1,0,4}) << endl; // 0
    cout << endl;
    cout << tab({2,3,1,1,4}) << endl; // 1
    cout << tab({3,2,1,0,4}) << endl; // 0
}
