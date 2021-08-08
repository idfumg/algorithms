#include "../../template.hpp"

int rec(const string& s, const int n, const char ch) {
    if (n == 0) return 0;
    if (s[n - 1] == 'b' and ch == 'b') return rec(s, n - 1, ch);
    if (s[n - 1] == 'a' and ch == 'a') return rec(s, n - 1, ch);
    if (s[n - 1] == 'a' and ch == 'b') return min(rec(s, n - 1, 'a'), rec(s, n - 1, 'b') + 1);
    return 1 + rec(s, n - 1, ch);
}

int rec(const string& s) {
    const int n = s.size();
    return min(rec(s, n, 'a'), rec(s, n, 'b'));
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (const int ch : {1, 0}) {
            if (s[i - 1] == 'b' and ch == 1) dp[i][ch] = dp[i - 1][ch];
            else if (s[i - 1] == 'a' and ch == 0) dp[i][ch] = dp[i - 1][ch];
            else if (s[i - 1] == 'a' and ch == 1) dp[i][ch] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            else dp[i][ch] = dp[i - 1][ch] + 1;
        }
    }
    return min(dp[n][0], dp[n][1]);
}

int tab_opt(const string& s) {
    const int n = s.size();
    vvi dp(2, vi(2));
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        idx = i & 1;
        for (const int ch : {1, 0}) {
            const char c = s[i - 1] - 'a';
            if (c == ch) dp[idx][ch] = dp[1 - idx][ch];
            else if (c == 0 and ch == 1) dp[idx][ch] = min(dp[1 - idx][0], dp[1 - idx][1] + 1);
            else dp[idx][ch] = 1 + dp[1 - idx][ch];
        }
    }
    return min(dp[idx][0], dp[idx][1]);
}

int tab2(const string& s) {
    const int n = s.size();
    const int K = 2;
    vvi dp(n + 1, vi(K + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            const int ch = s[i - 1] - 'a';
            if (ch == j)
                dp[i][j] = dp[i - 1][j];
            else if (ch < j)
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i - 1][ch]);
            else
                dp[i][j] = dp[i - 1][j] + 1;
        }
    }
    int ans = INF;
    for (int j = 0; j <= K; ++j) {
        ans = min(ans, dp[n][j]);
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
    cout << endl;
    cout << tab_opt("aababbab") << endl; // 2
    cout << tab_opt("bbaaaaabb") << endl; // 2
    cout << tab_opt("a") << endl; // 0
    cout << tab_opt("bbaaaaabbz") << endl; // 3
    cout << tab_opt("ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa") << endl; // 25
    cout << endl;
    cout << tab2("aababbab") << endl; // 2
    cout << tab2("bbaaaaabb") << endl; // 2
    cout << tab2("a") << endl; // 0
    cout << tab2("bbaaaaabbz") << endl; // 3
    cout << tab2("ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa") << endl; // 25
}
