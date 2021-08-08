#include "../../template.hpp"

int rec(const string& s, const int m, const int n) {
    static const string p = "abcdefghijklmnopqrstuvwxyz";
    if (m < 0) return 0;
    if (n < 0) return rec(s, m, p.size() - 1);
    if (s[m] == p[n]) return 1 + rec(s, m - 1, n - 1);
    return 0;
}

int rec(const string& s) {
    const int n = s.size();
    vi count(27);
    for (int i = n - 1; i >= 0; --i) {
        const char ch = s[i] - 'a';
        count[ch] = max(count[ch], rec(s, i, ch));
    }
    return reduce(count.begin(), count.end());
}

int rec2(const string& s, const int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (s[n] - s[n - 1] == 1 or (s[n] == 'a' and s[n - 1] == 'z')) return 1 + rec2(s, n - 1);
    return 1;
}

int rec2(const string& s) {
    const int n = s.size();
    array<int, 27> count{};
    for (int i = n - 1; i >= 0; --i) {
        const int ch = s[i] - 'a';
        count[ch] = max(count[ch], rec2(s, i));
    }
    return reduce(count.cbegin(), count.cend());
}

int tab(const string& s) {
    const int n = s.size();
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] - s[i - 1] == 1 or (s[i] == 'a' and s[i - 1] == 'z')) dp[i] = 1 + dp[i - 1];
        else dp[i] = 1;
    }
    array<int, 27> count{};
    for (int i = n - 1; i >= 0; --i) {
        const int ch = s[i] - 'a';
        count[ch] = max(count[ch], dp[i]);
    }
    return reduce(count.cbegin(), count.cend());
}

int tab_opt(const string& s) {
    const int n = s.size();
    array<int, 27> count{};
    count[s[0] - 'a'] = 1;
    vi dp(2);
    dp[0] = 1;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        idx = i & 1;
        if (s[i] - s[i - 1] == 1 or (s[i] == 'a' and s[i - 1] == 'z')) dp[idx] = 1 + dp[1 - idx];
        else dp[idx] = 1;
        const int ch = s[i] - 'a';
        count[ch] = max(count[ch], dp[idx]);
    }
    return reduce(count.cbegin(), count.cend());
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
    cout << endl;
    cout << tab("zab") << endl; // 6
    cout << tab("cac") << endl; // 2
    cout << tab("a") << endl; // 1
    cout << tab(s) << endl; // 33475
    cout << endl;
    cout << tab_opt("zab") << endl; // 6
    cout << tab_opt("cac") << endl; // 2
    cout << tab_opt("a") << endl; // 1
    cout << tab_opt(s) << endl; // 33475
}
