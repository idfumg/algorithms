#include "../../template.hpp"

vi GetCosts(string s) {
    int n = s.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + s[i - 1] - '0';
    }
    return prefix;
}

int rec(string a, string b, vi& prefixa, vi& prefixb, int m, int n) {
    if (m == 0) return prefixb[n];
    if (n == 0) return prefixa[m];
    if (a[m - 1] == b[n - 1]) return rec(a, b, prefixa, prefixb, m - 1, n - 1);
    return min(rec(a, b, prefixa, prefixb, m - 1, n) + a[m - 1] - '0',
               rec(a, b, prefixa, prefixb, m, n - 1) + b[n - 1] - '0');
}

int rec(string a, string b) {
    vi prefixa = GetCosts(a);
    vi prefixb = GetCosts(b);
    return rec(a, b, prefixa, prefixb, a.size(), b.size());
}

int tab1(string a, string b) {
    int m = a.size();
    int n = b.size();
    vi prefixa = GetCosts(a);
    vi prefixb = GetCosts(b);
    vvi dp(m + 1, vi(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) dp[i][j] = prefixb[j];
            else if (j == 0) dp[i][j] = prefixa[i];
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j] + a[i - 1] - '0',
                                dp[i][j - 1] + b[j - 1] - '0');
        }
    }
    return dp[m][n];
}

int tab2(const string& a, const string& b) { // we can just find answer fast here
    int m = a.size(), n = b.size();
    vi prefixa = GetCosts(a);
    vi prefixb = GetCosts(b);
    vvi dp(m + 1, vi(n + 1, INF));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] - '0') * 2;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return prefixa[m] + prefixb[n] - dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("3759", "9350") << endl; // 23
    cout << rec("3198", "98") << endl; // 4
    cout << '\n';
    cout << tab1("3759", "9350") << endl; // 23
    cout << tab1("3198", "98") << endl; // 4
    cout << '\n';
    cout << tab2("3759", "9350") << endl; // 23
    cout << tab2("3198", "98") << endl; // 4
}
