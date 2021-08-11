#include "../../template.hpp"

int rec(const string& s, const int n, const int ch) {
    if (n < 0) return 0;
    if (s[n] > ch) return 1 + rec(s, n - 1, ch);
    if (s[n] == ch) return rec(s, n - 1, ch);
    return min(rec(s, n - 1, ch) + 1, rec(s, n - 1, s[n]));
}

int rec(const string& s) {
    int ans = INF;
    for (const char ch : {'a', 'b'}) {
        ans = min(ans, rec(s, s.size() - 1, ch));
    }
    return ans;
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi('b' + 1));
    for (int i = 1; i <= n; ++i) {
        for (char ch = 'a'; ch <= 'b'; ++ch) {
            if (s[i - 1] > ch) dp[i][ch] = 1 + dp[i - 1][ch];
            else if (s[i - 1] == ch) dp[i][ch] = dp[i - 1][ch];
            else dp[i][ch] = min(dp[i - 1][ch] + 1, dp[i - 1][s[i - 1]]);
        }
    }
    int ans = INF;
    for (const char ch : {'a', 'b'}) {
        ans = min(ans, dp[n][ch]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec("aababbab") << endl; // 2
    cout << rec("bbaaaaabb") << endl; // 2
    cout << rec("a") << endl; // 0
    cout << rec("bbaaaaabbz") << endl; // 3
    cout << rec("ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa") << endl; // 25
    cout << endl;
    cout << tab("aababbab") << endl; // 2
    cout << tab("bbaaaaabb") << endl; // 2
    cout << tab("a") << endl; // 0
    cout << tab("bbaaaaabbz") << endl; // 3
    cout << tab("ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa") << endl; // 25
}
