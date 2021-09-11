#include "../../template.hpp"

bool is_lcs(const string& s, const string& t) {
    int m = s.size();
    int n = t.size();
    if (m > n) return 0;
    int i = 0;
    int j = 0;
    while (i < m and j < n) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        }
        else {
            ++j;
        }
    }
    return i == m;
}

string sol(const string& s, const vs& words) {
    string ans;
    for (const string& word : words) {
        if (is_lcs(word, s)) {
            if (word.size() > ans.size()) {
                ans = word;
            }
            else if (word.size() == ans.size() and word < ans) {
                ans = word;
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("abpcplea", {"ale","apple","monkey","plea"}) << endl; // apple
    cout << sol("abpcplea", {"a","b","c"}) << endl; // a
    cout << sol("aewfafwafjlwajflwajflwafj", {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"}) << endl; // ewaf
}
