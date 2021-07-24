#include "../../template.hpp"

int tab(const string& s) {
    int n = s.size();
    int ans = 0;
    vi dp(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] == '(') {
            dp[i] = 0;
        }
        else { // ')'
            if (s[i - 1] == '(') {
                dp[i] = 2;
                if (i >= 2) {
                    dp[i] += dp[i - 2];
                }
            }
            else { // ')'
                if (i - 1 - dp[i - 1] >= 0 and s[i - 1 - dp[i - 1]] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - 2 - dp[i - 1] >= 0) {
                        dp[i] += dp[i - 2 - dp[i - 1]];
                    }
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("") << endl; // 0
    cout << tab("(()") << endl; // 2
    cout << tab(")()())") << endl; // 4
    cout << tab("((()))") << endl; // 6
    cout << tab("()()") << endl; // 4
    cout << tab("()(())") << endl; // 6
    cout << tab("()(()") << endl; // 2
    cout << tab("()(()((()))") << endl; // 8
    cout << tab("(()())") << endl; // 6
    cout << tab("())") << endl; // 2
}
