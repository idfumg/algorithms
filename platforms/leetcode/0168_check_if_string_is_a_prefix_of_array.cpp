#include "../../template.hpp"

int sol(const string& s, const vector<string>& words) {
    const int n = s.size();
    if (n == 0 and not words.empty()) return 0;
    int idx = 0;
    for (const string& word : words) {
        for (int i = 0; i < word.size(); ++i) {
            if (idx == n) return 0;
            if (s[idx++] != word[i]) return 0;
        }
        if (idx == n) return 1;
    }
    return idx == n;
}

int main() { TimeMeasure _; __x();
    cout << sol("iloveleetcode", {"i","love","leetcode","apples"}) << endl; // 1
    cout << sol("iloveleetcode", {"apples","i","love","leetcode"}) << endl; // 0
    cout << sol("a", {"aa","aaaa","banana"}) << endl; // 0
    cout << sol("ccccccccc", {"c","cc"}) << endl; // 0
    cout << sol("", {"c","cc"}) << endl; // 0
}
