#include "../../template.hpp"

int sol(const string& s1, const string& s2, const string& s3, const int m, const int n, const int p, vvvi& dp) {
    if (m == 0 and n == 0) return dp[m][n][p] = 1;
    if (dp[m][n][p] != -1) return dp[m][n][p];
    if (m > 0 and s1[m - 1] == s3[p - 1] and sol(s1, s2, s3, m - 1, n, p - 1, dp)) return dp[m][n][p] = 1;
    if (n > 0 and s2[n - 1] == s3[p - 1] and sol(s1, s2, s3, m, n - 1, p - 1, dp)) return dp[m][n][p] = 1;
    return dp[m][n][p] = 0;
}

int sol(const string& s1, const string& s2, const string& s3) {
    vvvi dp(s1.size() + 1, vvi(s2.size() + 1, vi(s3.size() + 1, -1)));
    return s1.size() + s2.size() == s3.size() and sol(s1, s2, s3, s1.size(), s2.size(), s3.size(), dp);
}

int tab(const string& s1, const string& s2, const string& s3) {
    const int m = s1.size();
    const int n = s2.size();
    const int p = s3.size();
    vvvi dp(m + 1, vvi(n + 1, vi(p + 1)));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= p; ++k) {
                if (i == 0 and j == 0) dp[i][j][k] = 1;
                else if (i > 0 and k > 0 and s1[i - 1] == s3[k - 1] and dp[i - 1][j][k - 1]) dp[i][j][k] = 1;
                else if (j > 0 and k > 0 and s2[j - 1] == s3[k - 1] and dp[i][j - 1][k - 1]) dp[i][j][k] = 1;
            }
        }
    }
    return m + n == p and dp[m][n][p];
}

int sol2(const string& s1, const string& s2, const string& s3, const int m, const int n, vvi& dp) {
    const int p = m + n;
    if (m == 0 and n == 0) return dp[m][n] = 1;
    if (dp[m][n] != -1) return dp[m][n];
    if (m > 0 and s1[m - 1] == s3[p - 1] and sol2(s1, s2, s3, m - 1, n, dp)) return dp[m][n] = 1;
    if (n > 0 and s2[n - 1] == s3[p - 1] and sol2(s1, s2, s3, m, n - 1, dp)) return dp[m][n] = 1;
    return dp[m][n] = 0;
}

int sol2(const string& s1, const string& s2, const string& s3) {
    vvi dp(s1.size() + 1, vi(s2.size() + 1, -1));
    return s1.size() + s2.size() == s3.size() and sol2(s1, s2, s3, s1.size(), s2.size(), dp);
}

int tab2(const string& s1, const string& s2, const string& s3) {
    const int m = s1.size();
    const int n = s2.size();
    const int p = s3.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            const int k = i + j;
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (i > 0 and k <= p and s1[i - 1] == s3[k - 1] and dp[i - 1][j]) dp[i][j] = 1;
            else if (j > 0 and k <= p and s2[j - 1] == s3[k - 1] and dp[i][j - 1]) dp[i][j] = 1;
        }
    }
    return m + n == p and dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << sol("aabcc", "dbbca", "aadbbcbcac") << endl; // 1
    cout << sol("aabcc", "dbbca", "aadbbbaccc") << endl; // 0
    cout << sol("", "", "") << endl; // 1
    cout << sol("a", "b", "a") << endl; // 0
    cout << sol("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab", "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb", "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab") << endl; // 0
    cout << sol("a", "", "c") << endl; // 0
    cout << sol("", "", "a") << endl; // 0
    cout << endl;
    cout << tab("aabcc", "dbbca", "aadbbcbcac") << endl; // 1
    cout << tab("aabcc", "dbbca", "aadbbbaccc") << endl; // 0
    cout << tab("", "", "") << endl; // 1
    cout << tab("a", "b", "a") << endl; // 0
    cout << tab("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab", "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb", "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab") << endl; // 0
    cout << tab("a", "", "c") << endl; // 0
    cout << tab("", "", "a") << endl; // 0
    cout << endl;
    cout << sol2("aabcc", "dbbca", "aadbbcbcac") << endl; // 1
    cout << sol2("aabcc", "dbbca", "aadbbbaccc") << endl; // 0
    cout << sol2("", "", "") << endl; // 1
    cout << sol2("a", "b", "a") << endl; // 0
    cout << sol2("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab", "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb", "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab") << endl; // 0
    cout << sol2("a", "", "c") << endl; // 0
    cout << sol2("", "", "a") << endl; // 0
    cout << endl;
    cout << tab2("aabcc", "dbbca", "aadbbcbcac") << endl; // 1
    cout << tab2("aabcc", "dbbca", "aadbbbaccc") << endl; // 0
    cout << tab2("", "", "") << endl; // 1
    cout << tab2("a", "b", "a") << endl; // 0
    cout << tab2("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab", "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb", "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab") << endl; // 0
    cout << tab2("a", "", "c") << endl; // 0
    cout << tab2("", "", "a") << endl; // 0
    cout << tab2("aaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl; // 0
}
