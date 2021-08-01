#include "../../template.hpp"

bool rec(const string& s, const int x, const int y, const int n, vi& dp) {
    if (n <= 1) return dp[n] = true;
    if (s[n - 1] == '1') return dp[n] = false;
    if (dp[n] != -1) return dp[n];
    for (int k = x; k <= y and n - k >= 0; ++k) {
        if (rec(s, x, y, n - k, dp)) {
            return dp[n] = true;
        }
    }
    return dp[n] = false;
}

bool rec(const string& s, const int x, const int y) {
    vi dp(s.size() + 1, -1);
    return rec(s, x, y, s.size(), dp);
}

bool tab(const string& s, const int x, const int y) {
    const int n = s.size();
    vi dp(n + 1, 0);
    dp[1] = 1;
    multiset<int> set{};
    for (int i = x; i <= n; ++i) {
        if (i - y - 1 >= 1) set.erase(set.find(dp[i - y - 1]));

        if (s[i - 1] == '1') dp[i] = 0;
        else if (not set.empty()) dp[i] = *crbegin(set);

        set.insert(dp[i - x + 1]);
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec("011010", 2, 3) << endl; // 1
    cout << rec("01101110", 2, 3) << endl; // 0
    cout << rec("00111010", 3, 5) << endl; // 0
    cout << rec("00", 1, 1) << endl; // 1
    cout << endl;
    cout << tab("011010", 2, 3) << endl; // 1
    cout << tab("01101110", 2, 3) << endl; // 0
    cout << tab("00111010", 3, 5) << endl; // 0
    cout << tab("00", 1, 1) << endl; // 1
}
