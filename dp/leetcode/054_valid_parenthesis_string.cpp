#include "../../template.hpp"

int rec(const string& s, const int n, const int right) {
    if (n == 0 and right == 0) return 1;
    if (n == 0) return 0;
    if (s[n - 1] == ')') return rec(s, n - 1, right + 1);
    if (s[n - 1] == '(' and right > 0) return rec(s, n - 1, right - 1);
    if (s[n - 1] == '(') return 0;
    return rec(s, n - 1, right + 1) or rec(s, n - 1, right - 1) or rec(s, n - 1, right);
}

int rec(const string& s) {
    return rec(s, s.size(), 0);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi(n + 2));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else if (s[i - 1] == ')') dp[i][j] = dp[i - 1][j + 1];
            else if (s[i - 1] == '(' and j > 0) dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] == '(') dp[i][j] = 0;
            else dp[i][j] =
                     dp[i - 1][j + 1] or
                     (j > 0 ? dp[i - 1][j - 1] : 0) or
                     dp[i - 1][j];
        }
    }
    return dp[n][0];
}

int tab2(const string& s) {
    const int n = s.size();
    vvi dp(2, vi(n + 2));
    int idx = 0;
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = n; j >= 0; --j) {
            if (i == 0 and j == 0) dp[idx][j] = 1;
            else if (i == 0) dp[idx][j] = 0;
            else if (s[i - 1] == ')') dp[idx][j] = dp[1 - idx][j + 1];
            else if (s[i - 1] == '(' and j > 0) dp[idx][j] = dp[1 - idx][j - 1];
            else if (s[i - 1] == '(') dp[idx][j] = 0;
            else dp[idx][j] =
                     dp[1 - idx][j + 1] or
                     (j > 0 ? dp[1 - idx][j - 1] : 0) or
                     dp[1 - idx][j];
        }
    }
    return dp[idx][0];
}

int main() { TimeMeasure _; __x();
    cout << rec(")") << endl; // 0
    cout << rec(")(") << endl; // 0
    cout << rec("()(") << endl; // 0
    cout << rec("()") << endl; // 1
    cout << rec("(*)") << endl; // 1
    cout << rec("(*))") << endl; // 1
    cout << rec("(((((()*)(*)*))())())(()())())))((**)))))(()())()") << endl; // 0
    cout << endl;
    cout << tab(")") << endl; // 0
    cout << tab(")(") << endl; // 0
    cout << tab("()(") << endl; // 0
    cout << tab("()") << endl; // 1
    cout << tab("(*)") << endl; // 1
    cout << tab("(*))") << endl; // 1
    cout << tab("(((((()*)(*)*))())())(()())())))((**)))))(()())()") << endl; // 0
    cout << endl;
    cout << tab2(")") << endl; // 0
    cout << tab2(")(") << endl; // 0
    cout << tab2("()(") << endl; // 0
    cout << tab2("()") << endl; // 1
    cout << tab2("(*)") << endl; // 1
    cout << tab2("(*))") << endl; // 1
    cout << tab2("(((((()*)(*)*))())())(()())())))((**)))))(()())()") << endl; // 0
}
