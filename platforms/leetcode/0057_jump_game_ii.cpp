#include "../../template.hpp"

int rec(const vi& arr, const int n) {
    if (n == arr.size()) return 0;
    int count = INF;
    for (int k = 1; k <= arr[n - 1] and n + k <= arr.size(); ++k) {
        count = min(count, rec(arr, n + k) + 1);
    }
    return count;
}

int rec(const vi& arr) {
    return rec(arr, 1);
}

int tab(const vi& arr) {
    int n = arr.size();
    vi dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        for (int k = 1; k <= arr[i - 1] and i + k <= arr.size(); ++k) {
            dp[i] = min(dp[i], dp[i + k] + 1);
        }
    }
    return dp[1];
}

int main() { TimeMeasure _; __x();
    cout << rec({2,3,1,1,4}) << endl; // 2
    cout << rec({2,3,0,1,4}) << endl; // 2
    cout << rec({2,1}) << endl; // 1
    cout << rec({1,2,3,4}) << endl; // 2
    cout << endl;
    cout << tab({2,3,1,1,4}) << endl; // 2
    cout << tab({2,3,0,1,4}) << endl; // 2
    cout << tab({2,1}) << endl; // 1
    cout << tab({1,2,3,4}) << endl; // 2
}
