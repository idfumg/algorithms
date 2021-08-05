#include "../../template.hpp"

int tab(const string& s) {
    int n = s.size();
    vi dp(n, 1);
    int maxi = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[i] == s[j] or (s[i] == 'b' and s[j] == 'a')) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return n - maxi;
}

int rec(const string& s, const int n, const int last) {
    if (n == 0) return 0;
    if (s[n - 1] == last) return rec(s, n - 1, last);
    if (s[n - 1] < last) return min(rec(s, n - 1, 'b') + 1, rec(s, n - 1, 'a'));
    return rec(s, n - 1, last) + 1;
}

int rec(const string& s) {
    return min(rec(s, s.size(), 'a'), rec(s, s.size(), 'b'));
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
    cout << tab("aababbab") << endl; // 2
    cout << tab("bbaaaaabb") << endl; // 2
    cout << tab("a") << endl; // 0
    cout << endl;
    cout << rec("aababbab") << endl; // 2
    cout << rec("bbaaaaabb") << endl; // 2
    cout << rec("a") << endl; // 0
    cout << endl;
    cout << tab2("aababbab") << endl; // 2
    cout << tab2("bbaaaaabb") << endl; // 2
    cout << tab2("a") << endl; // 0
    cout << tab2("bbaaaaabbz") << endl; // 3
    cout << endl;
}
