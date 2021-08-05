#include "../../template.hpp"

int naive(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    vector<string> strs1;
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            strs1.push_back(a.substr(i, j - i + 1));
        }
    }
    vector<string> strs2;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            strs2.push_back(b.substr(i, j - i + 1));
        }
    }
    int ans = 0;
    for (const auto& str1 : strs1) {
        for (const auto& str2 : strs2) {
            if (str1.size() == str2.size()) {
                int count = 0;
                for (int i = 0; i < str1.size(); ++i) {
                    count += str1[i] != str2[i];
                    if (count > 1) break;
                }
                ans += count == 1;
            }
        }
    }
    return ans;
}

int rec(const string& a, const string& b, const int m, const int n, const int k) {
    if (m < 0 or n < 0 or k < 0) return 0;
    if (a[m] != b[n] and k == 0) return 0;
    if (a[m] != b[n] and k != 0) return 1 + rec(a, b, m - 1, n - 1, k - 1);
    if (a[m] == b[n] and k == 0) return 1 + rec(a, b, m - 1, n - 1, 0);
    return rec(a, b, m - 1, n - 1, k);
}

int rec(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            const int k = 1;
            ans += rec(a, b, i, j, k);
        }
    }
    return ans;
}

int tab(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    int ans = 0;
    vvvi dp(m + 1, vvi(n + 1, vi(1 + 1)));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (const int k : {0, 1}) {
                if (a[i] != b[j] and k == 0)
                    dp[i][j][k] = 0;
                else if (a[i] != b[j] and k != 0)
                    dp[i][j][k] = 1 + (i > 0 and j > 0 ? dp[i - 1][j - 1][0] : 0);
                else if (a[i] == b[j] and k == 0)
                    dp[i][j][k] = 1 + (i > 0 and j > 0 ? dp[i - 1][j - 1][0] : 0);
                else
                    dp[i][j][k] = (i > 0 and j > 0 ? dp[i - 1][j - 1][k] : 0);
                if (k == 1) ans += dp[i][j][k];
            }
        }
    }
    return ans;
}

int tab_opt(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    int ans = 0, idx = 0;
    vvvi dp(2, vvi(n + 1, vi(2)));
    for (int i = 0; i < m; ++i) {
        idx = i & 1;
        for (int j = 0; j < n; ++j) {
            for (const int k : {0, 1}) {
                if (a[i] != b[j] and k == 0)
                    dp[idx][j][k] = 0;
                else if (a[i] != b[j] and k != 0)
                    dp[idx][j][k] = 1 + (i > 0 and j > 0 ? dp[1 - idx][j - 1][0] : 0);
                else if (a[i] == b[j] and k == 0)
                    dp[idx][j][k] = 1 + (i > 0 and j > 0 ? dp[1 - idx][j - 1][0] : 0);
                else
                    dp[idx][j][k] = (i > 0 and j > 0 ? dp[1 - idx][j - 1][k] : 0);
                if (k == 1) ans += dp[idx][j][k];
            }
        }
    }
    return ans;
}

int tab2(const string& a, const string& b) {
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
    cout << endl;
    cout << tab_opt("aba", "baba") << endl; // 6
    cout << tab_opt("ab", "bb") << endl; // 3
    cout << tab_opt("a", "a") << endl; // 0
    cout << tab_opt("abe", "bbc") << endl; // 10
    cout << endl;
    cout << tab2("aba", "baba") << endl; // 6
    cout << tab2("ab", "bb") << endl; // 3
    cout << tab2("a", "a") << endl; // 0
    cout << tab2("abe", "bbc") << endl; // 10
}
