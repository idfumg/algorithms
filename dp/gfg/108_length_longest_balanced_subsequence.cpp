#include "../../template.hpp"

bool IsBalanced(const string& s) {
    int left = 0;
    for (const char ch : s) {
        if (ch == '(') ++left;
        else if (left-- == 0) return false;
    }
    return left == 0;
}

int naive(const string& s) {
    const int n = s.size();
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        if (not temp.empty() and IsBalanced(temp)) {
            ans = max({ans, static_cast<int>(temp.size())});
        }
    }
    return ans;
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 2; i <= n; ++i) {
        if (s[i - 2] == '(' and s[i - 1] == ')') {
            dp[i - 1][i] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == '(' and s[j - 2] == ')') {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            for (int p = i + 1; p < j; ++p) {
                dp[i][j] = max(dp[i][j], dp[i][p] + dp[p + 1][j]);
            }
        }
    }
    return dp[1][n];
}

int rec(const string& s, int i, int j) {
    if (i >= j) return 0;
    int maxi = 0;
    if (s[i - 1] == '(' and s[j - 1] == ')') {
        maxi = rec(s, i + 1, j - 1) + 2;
    }
    for (int p = i + 1; p < j; ++p) {
        maxi = max(maxi, rec(s, i, p) + rec(s, p + 1, j));
    }
    return maxi;
}

int rec(const string& s) {
    return rec(s, 1, s.size());
}

int main() { TimeMeasure _; __x();
    cout << IsBalanced("()()") << '\n'; // true
    cout << IsBalanced("()())") << '\n'; // false
    cout << IsBalanced("()(((((()") << '\n'; // false
    cout << IsBalanced("((()))") << '\n'; // true
    cout << IsBalanced("()") << '\n'; // true
    cout << '\n';
    cout << naive("()())") << '\n'; // 4
    cout << naive("()(((((()") << '\n'; // 4
    cout << naive("((()))") << '\n'; // 6
    cout << naive("())") << '\n'; // 2
    cout << '\n';
    cout << tab("()())") << '\n'; // 4
    cout << tab("()(((((()") << '\n'; // 4
    cout << tab("((()))") << '\n'; // 6
    cout << tab("())") << '\n'; // 2
    cout << '\n';
    cout << rec("()())") << '\n'; // 4
    cout << rec("()(((((()") << '\n'; // 4
    cout << rec("((()))") << '\n'; // 6
    cout << rec("())") << '\n'; // 2
}
