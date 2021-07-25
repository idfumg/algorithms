#include "../../template.hpp"

static const string a = "abcdefghijklmnopqrstuvwxyz";

int rec(vvi& dp, const string& b, const int n, const int m) {
    static const string a = "abcdefghijklmnopqrstuvwxyz";
    if (n == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (m == 0) return dp[n][m] = rec(dp, b, n, a.size());
    if (a[m - 1] == b[n - 1]) return dp[n][m] = 1 + rec(dp, b, n - 1, m - 1);
    return 0;
}

int rec(const string& b) {
    const int n = b.size();
    const int CHARS_SIZE = 27;
    vi count(CHARS_SIZE);
    vvi dp(n + 1, vi(CHARS_SIZE, -1));
    for (int i = n; i >= 1; --i) {
        const int ch = b[i - 1] - 'a' + 1;
        count[ch] = max(count[ch], rec(dp, b, i, ch));
    }
    return reduce(cbegin(count), cend(count));
}

int rec2(vi& dp, const string& b, const int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    if ((b[n - 1] - b[n - 2] == 1) or (b[n - 1] == 'a' and b[n - 2] == 'z'))
        return dp[n] = 1 + rec2(dp, b, n - 1);
    return 1;
}

int rec2(const string& b) {
    const int n = b.size();
    const int CHARS_SIZE = 27;
    vi count(CHARS_SIZE);
    vi dp(n + 1, -1);
    for (int i = n; i >= 1; --i) {
        const int ch = b[i - 1] - 'a' + 1;
        count[ch] = max(count[ch], rec2(dp, b, i));
    }
    return reduce(cbegin(count), cend(count));
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
