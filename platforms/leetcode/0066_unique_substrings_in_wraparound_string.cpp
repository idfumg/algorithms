#include "../../template.hpp"

int rec(const string& s, vi& dp, const int n) {
    if (dp[n] != -1) return dp[n];
    if (n <= 1) return n;
    if ((s[n - 1] - s[n - 2] == 1) or (s[n - 1] == 'a' and s[n - 2] == 'z')) {
        return dp[n] = 1 + rec(s, dp, n - 1);
    }
    return dp[n] = 1;
}

int rec(const string& s) {
    const int n = s.size();
    array<int, 27> count{};
    vi dp(n + 1, -1);
    for (int i = n; i >= 1; --i) {
        const int ch = s[i - 1] - 'a';
        count[ch] = max(count[ch], rec(s, dp, i));
    }
    return reduce(count.begin(), count.end());
}

int rec2(const string& s, vvi& dp, const int n, const int m) {
    static const string a = "abcdefghijklmnopqrstuvwxyz";
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0) return 0;
    if (m == 0) return dp[n][m] = rec2(s, dp, n, a.size());
    if (s[n - 1] == a[m - 1]) return dp[n][m] = 1 + rec2(s, dp, n - 1, m - 1);
    return dp[n][m] = 0;
}

int rec2(const string& s) {
    const int n = s.size();
    array<int, 27> count{};
    vvi dp(n + 1, vi(27, -1));
    for (int i = n; i >= 1; --i) {
        const int m = s[i - 1] - 'a' + 1;
        count[m] = max(count[m], rec2(s, dp, i, m));
    }
    return reduce(count.begin(), count.end());
}

int main() { TimeMeasure _; __x();
    const string s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

    cout << rec("zab") << endl; // 6
    cout << rec("cac") << endl; // 2
    cout << rec("a") << endl; // 1
    cout << rec(s) << endl; // 33475
    cout << endl;
    cout << rec2("zab") << endl; // 6
    cout << rec2("cac") << endl; // 2
    cout << rec2("a") << endl; // 1
    cout << rec2(s) << endl; // 33475
}
