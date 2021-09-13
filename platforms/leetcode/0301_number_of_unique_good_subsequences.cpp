#include "../../template.hpp"

void brute(const string& s, const int n, unordered_set<string>& ans, string& current) {
    if (current.size() > 1 and current.front() == '0') {
        return;
    }
    if (n == s.size()) {
        if (not current.empty()) {
            ans.insert(current);
        }
        return;
    }

    current += s[n];
    brute(s, n + 1, ans, current);
    current.pop_back();
    brute(s, n + 1, ans, current);
}

int brute(const string& s) {
    unordered_set<string> ans;
    string current;
    brute(s, 0, ans, current);
    return ans.size();
}

int sol(const string& s) {
    int n = s.size();
    bool was_zero = false;
    vvi dp(2, vi(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            was_zero = true;
            dp[0][i] = (1ll + dp[0][i + 1] + dp[1][i + 1]) % MOD;
            dp[1][i] = dp[1][i + 1];
        }
        else {
            dp[1][i] = (1ll + dp[0][i + 1] + dp[1][i + 1]) % MOD;
            dp[0][i] = dp[0][i + 1];
        }
    }
    return (dp[1][0] + was_zero) % MOD;
}

int main() { TimeMeasure _; __x();
    cout << brute("001") << endl; // 2
    cout << brute("11") << endl; // 2
    cout << brute("101") << endl; // 5
    cout << 6617449 << endl; // cout << brute("111001101100000001001110110101110001100") << endl; // 6617449
    cout << endl;
    cout << sol("001") << endl; // 2
    cout << sol("11") << endl; // 2
    cout << sol("101") << endl; // 5
    cout << sol("111001101100000001001110110101110001100") << endl; // 6617449
    cout << sol("1100100010101010100100000111110001111001000010000010010111011") << endl; // 846803618
}
