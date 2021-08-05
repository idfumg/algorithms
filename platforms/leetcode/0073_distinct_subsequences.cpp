#include "../../template.hpp"

int rec_count(const string& a, const string& b, const int m, const int n) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (a[m - 1] == b[n - 1])
        return rec_count(a, b, m - 1, n - 1) + rec_count(a, b, m - 1, n);
    return rec_count(a, b, m - 1, n);
}

int rec_count(const string& a, const string& b) {
    return rec_count(a, b, a.size(), b.size());
}

void rec(const string& a, const string& b, const int m, const int n, vector<string>& res, string& current) {
    if (n == 0) {
        string temp = current;
        reverse(temp.begin(), temp.end());
        res.push_back(temp);
        return;
    }
    if (m == 0) {
        return;
    }
    if (a[m - 1] == b[n - 1]) {
        current += a[m - 1];
        rec(a, b, m - 1, n - 1, res, current);
        current.pop_back();
        rec(a, b, m - 1, n, res, current);
    }
    else {
        rec(a, b, m - 1, n, res, current);
    }
}

vector<string> rec(const string& a, const string& b) {
    vector<string> res;
    string current;
    rec(a, b, a.size(), b.size(), res, current);
    return res;
}

int tab_count(const string& a, const string& b) {
    const int m = a.size();
    const int n = b.size();
    int idx = 0;
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        idx = i & 1;
        for (int j = 0; j <= n; ++j) {
            if (j == 0) dp[idx][j] = 1;
            else if (i == 0) dp[idx][j] = 0;
            else if (a[i - 1] == b[j - 1]) dp[idx][j] = dp[1 - idx][j - 1] + dp[1 - idx][j];
            else dp[idx][j] = dp[1 - idx][j];
            dp[idx][j] = dp[idx][j] % MOD;
        }
    }
    return dp[idx][n];
}

int main() { TimeMeasure _; __x();
    cout << rec_count("rabbbit", "rabbit") << endl; // 3
    cout << rec_count("babgbag", "bag") << endl; // 5
    cout << endl;
    cout << rec("rabbbit", "rabbit") << endl;
    cout << rec("babgbag", "bag") << endl;
    cout << endl;
    cout << tab_count("rabbbit", "rabbit") << endl;
    cout << tab_count("babgbag", "bag") << endl;
}
