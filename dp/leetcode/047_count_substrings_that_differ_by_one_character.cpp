#include "../../template.hpp"

int naive(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    int ans = 0;
    vector<string> tab1;
    vector<string> tab2;
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            tab1.push_back(a.substr(i, j - i + 1));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tab2.push_back(b.substr(i, j - i + 1));
        }
    }
    for (const auto& s1 : tab1) {
        for (const auto& s2 : tab2) {
            if (s1.size() == s2.size()) {
                int count = 0;
                for (int k = 0; k < s1.size(); ++k) {
                    if (count > 1) break;
                    if (s1[k] != s2[k]) ++count;
                }
                ans += count == 1;
            }
        }
    }
    return ans;
}

int rec(const string& a, const string& b, const int m, const int n, const int k) {
    if (m < 0 or n < 0 or k < 0) return 0;
    if (k == 0 and a[m] != b[n]) return 0;
    if (k != 0 and a[m] != b[n]) {
        return rec(a, b, m - 1, n - 1, k - 1) + 1;
    }
    if (k == 0 and a[m] == b[n]) {
        return rec(a, b, m - 1, n - 1, 0) + 1;
    }
    return rec(a, b, m - 1, n - 1, k);
}

int rec(const string& a, const string& b) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            ans += rec(a, b, i, j, 1);
        }
    }
    return ans;
}

int tab(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    vvvi dp(m + 1, vvi(n + 1, vi(2)));
    for (int i = 0; i < m; ++i) {
        dp[i][0][0] = a[i] == b[0] ? 1 : 0;
        dp[i][0][1] = a[i] != b[0] ? 1 : 0;
    }
    for (int j = 1; j < n; ++j) {
        dp[0][j][0] = a[0] == b[j] ? 1 : 0;
        dp[0][j][1] = a[0] != b[j] ? 1 : 0;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int k : {1, 0}) {
                if (k == 0 and a[i] != b[j]) {
                    dp[i][j][k] = 0;
                }
                else if (k != 0 and a[i] != b[j]) {
                    dp[i][j][k] = dp[i - 1][j - 1][0] + 1;
                }
                else if (k == 0 and a[i] == b[j]) {
                    dp[i][j][k] = dp[i - 1][j - 1][0] + 1;
                }
                else {
                    dp[i][j][k] = dp[i - 1][j - 1][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += dp[i][j][1];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << naive("aba", "baba") << endl; // 6
    cout << naive("ab", "bb") << endl; // 3
    cout << naive("a", "a") << endl; // 0
    cout << naive("abe", "bbc") << endl; // 10
    cout << endl;
    cout << rec("aba", "baba") << endl; // 6
    cout << rec("ab", "bb") << endl; // 3
    cout << rec("a", "a") << endl; // 0
    cout << rec("abe", "bbc") << endl; // 10
    cout << endl;
    cout << tab("aba", "baba") << endl; // 6
    cout << tab("ab", "bb") << endl; // 3
    cout << tab("a", "a") << endl; // 0
    cout << tab("abe", "bbc") << endl; // 10
}
