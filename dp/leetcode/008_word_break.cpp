#include "../../template.hpp"

bool rec(const string& s, const unordered_set<string>& words, const int n, const int count) {
    if (n == 0 and count == 1) return true;
    if (n == 0 and count != 1) return false;

    const auto word = s.substr(n - 1, count);
    if (words.count(word) and rec(s, words, n - 1, 1)) return true;
    return rec(s, words, n - 1, count + 1);
}

bool rec(const string& s, const unordered_set<string>& words) {
    return rec(s, words, s.size(), 1);
}

bool tab(const string& s, const unordered_set<string>& words) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 2));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            const auto word = s.substr(i - 1, j);
            if (words.count(word) and dp[i - 1][1]) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j + 1];
        }
    }
    return dp[n][1];
}

int main() { TimeMeasure _; __x();
    cout << rec("catsanddog", {"cat","cats","and","sand","dog"}) << endl;
    cout << rec("pineapplepenapple", {"apple","pen","applepen","pine","pineapple"}) << endl;
    cout << rec("catsandog", {"cats","dog","sand","and","cat"}) << endl;
    cout << endl;
    cout << tab("catsanddog", {"cat","cats","and","sand","dog"}) << endl;
    cout << tab("pineapplepenapple", {"apple","pen","applepen","pine","pineapple"}) << endl;
    cout << tab("catsandog", {"cats","dog","sand","and","cat"}) << endl;
}
