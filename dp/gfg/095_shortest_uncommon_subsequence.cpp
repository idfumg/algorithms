#include "../../template.hpp"

void find_subsequences(string s, set<string>& seqs, string& current, int n) {
    if (n == 0) {
        seqs.insert(current);
        return;
    }
    find_subsequences(s, seqs, current, n - 1);
    current.push_back(s[n - 1]);
    find_subsequences(s, seqs, current, n - 1);
    current.pop_back();
}

set<string> find_subsequences(string s) {
    set<string> seqs;
    string current;
    find_subsequences(s, seqs, current, s.size());
    return seqs;
}

int brute(string s1, string s2) {
    const auto s1parts = find_subsequences(s1);
    const auto s2parts = find_subsequences(s2);

    int ans = INF;
    for (const auto& part : s1parts) {
        if (not s2parts.count(part)) {
            ans = min(ans, (int)part.size());
        }
    }
    return ans == INF ? -1 : ans;
}

set<string> FindSubseqs(string s) {
    int n = s.size();
    set<string> ans;
    for (int i = 0; i < (1 << n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        ans.insert(move(temp));
    }
    return ans;
}

int brute2(string a, string b) {
    const auto first = FindSubseqs(a);
    const auto second = FindSubseqs(b);

    size_t ans = INF;
    for (const auto& subseq : first) {
        if (not second.count(subseq)) {
            ans = min(ans, subseq.size());
        }
    }
    return ans == INF ? -1 : ans;
}

int rec(string a, string b, int m, int n) {
    if (m == 0) return INF; // nothing in the a that is not in the b
    if (n == 0) return 1; // everything in the a not in the b

    int k = n; // find if the current character exists in the b
    for (; k > 0 and a[m - 1] != b[k - 1]; --k) {}
    if (k == 0) return 1;

    return min(1 + rec(a, b, m - 1, k - 1), rec(a, b, m - 1, n)); // append or not
}

int rec(string a, string b) {
    int ans = rec(a, b, a.size(), b.size());
    return ans == INF ? -1 : ans;
}

int tab(string a, string b) {
    int m = a.size();
    int n = b.size();
    vvi dp(m + 1, vi(n + 1, INF));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) dp[i][j] = INF;
            else if (j == 0) dp[i][j] = 1;
            else {
                int k = j;
                for (; k > 0 and a[i - 1] != b[k - 1]; --k) {}
                if (k == 0) dp[i][j] = 1;
                else dp[i][j] = min(1 + dp[i - 1][k - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n] == INF ? -1 : dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << brute("babab", "babba") << endl; // 3
    cout << brute("abb", "abab") << endl; // -1
    cout << endl;
    cout << brute2("babab", "babba") << endl; // 3
    cout << brute2("abb", "abab") << endl; // -1
    cout << endl;
    cout << rec("babab", "babba") << endl; // 3
    cout << rec("abb", "abab") << endl; // -1
    cout << endl;
    cout << tab("babab", "babba") << endl; // 3
    cout << tab("abb", "abab") << endl; // -1
}
