#include "../../template.hpp"

template<class T>
int rec(const T& arr, const int n) {
    if (n <= 0) return 0;
    if (arr[n - 1] == 0) return rec(arr, n - 1);
    return max(rec(arr, n - 1), rec(arr, n - 2) + arr[n - 1]);
}

int rec(const vi& arr) {
    array<int, 10001> elems{};
    for (const int elem : arr) {
        elems[elem] += elem;
    }
    return rec(elems, elems.size());
}

int tab(const vi& elems) {
    array<int, 10001> arr{};
    for (const int elem : elems) {
        arr[elem] += elem;
    }
    const int n = arr.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], (i - 2 >= 0 ? dp[i - 2] : 0) + arr[i - 1]);
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec({3,4,2}) << endl; // 6
    cout << rec({2,2,3,3,3,4}) << endl; // 9
    cout << endl;
    cout << tab({3,4,2}) << endl; // 6
    cout << tab({2,2,3,3,3,4}) << endl; // 9
}
