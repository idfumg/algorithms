#include "../../template.hpp"

int rec(const string& s, const int i, const int j) {
    if (i >= j) return 1;
    return s[i - 1] == s[j - 1] and rec(s, i + 1, j - 1);
}

int rec(const string& s) {
    const int n = s.size();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans += rec(s, i, j);
        }
    }
    return ans;
}

int tab(const string& s) {
    const int n = s.size();
    int count = 0;
    vvi ispalindrome(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) ispalindrome[i][j] = 0;
            else if (i == j) ispalindrome[i][j] = 1;
            else if (j - i == 1) ispalindrome[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) ispalindrome[i][j] = ispalindrome[i + 1][j - 1];
            count += ispalindrome[i][j];
        }
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << rec("abc") << endl; // 3
    cout << rec("aaa") << endl; // 6
    cout << rec("aaaaa") << endl; // 15
    cout << endl;
    cout << tab("abc") << endl; // 3
    cout << tab("aaa") << endl; // 6
    cout << tab("aaaaa") << endl; // 15
}
