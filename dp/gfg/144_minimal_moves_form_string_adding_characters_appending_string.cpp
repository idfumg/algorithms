#include "../../template.hpp"

int rec(string s, int n) {
    if (n == 0) return 0;
    if (n % 2 == 0) return 1 + rec(s, n / 2);
    return 1 + rec(s, n - 1);
}

int rec(string s) {
    int n = s.size();
    return rec(s, n);
}

int tab(string s) {
    int n = s.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) dp[i] = 1 + dp[i / 2];
        else dp[i] = 1 + dp[i - 1];
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    string s1 = "aaaaaaaa"; // 4
    string s2 = "aaaaaa"; // 4
    string s3 = "abcabca"; // 5
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << '\n';
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
}
