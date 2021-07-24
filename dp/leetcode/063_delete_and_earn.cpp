#include "../../template.hpp"

int rec(const vi& arr, const int n) {
    if (n <= 0) return 0;
    return max(rec(arr, n - 2) + arr[n - 1], rec(arr, n - 1));
}

int rec(vi arr) {
    sort(begin(arr), end(arr));
    const int n = *max_element(cbegin(arr), cbegin(arr));
    vi values(n + 3);
    for (const int value : arr) {
        values[value] += value;
    }
    return rec(values, values.size());
}

int tab(vi arr) {
    sort(begin(arr), end(arr));
    const int N = *max_element(cbegin(arr), cend(arr));
    vi values(N + 3);
    for (const int value : arr) {
        values[value] += value;
    }
    const int n = values.size();
    vi dp(n + 1);
    dp[1] = values[0];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + values[i - 1], dp[i - 1]);
    }
    return dp[n];
}

int tab2(vi arr) {
    sort(begin(arr), end(arr));
    const int N = *max_element(cbegin(arr), cend(arr));
    vi values(N + 3);
    for (const int value : arr) {
        values[value] += value;
    }
    const int n = values.size();
    vi dp(3);
    dp[1] = values[0];
    for (int i = 2; i <= n; ++i) {
        dp[i % 3] = max(dp[(i + 1) % 3] + values[i - 1], dp[(i + 2) % 3]);
    }
    return dp[n % 3];
}

int main() { TimeMeasure _; __x();
    cout << rec({3,4,2}) << endl; // 6
    cout << rec({2,2,3,3,3,4}) << endl; // 9
    cout << endl;
    cout << tab({3,4,2}) << endl; // 6
    cout << tab({2,2,3,3,3,4}) << endl; // 9
    cout << endl;
    cout << tab2({3,4,2}) << endl; // 6
    cout << tab2({2,2,3,3,3,4}) << endl; // 9
}
