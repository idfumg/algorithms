#include "../../template.hpp"

int sol(const string& s, const string& t) {
    if (s.size() != t.size()) return 0;
    const int n = s.size();
    unordered_map<char, char> m;
    unordered_set<char> assigned;
    for (int i = 0; i < n; ++i) {
        if (m.count(s[i]) and m[s[i]] != t[i]) return 0;
        if (m.count(s[i]) and m[s[i]] == t[i]) continue;
        if (assigned.count(t[i])) return 0;
        assigned.insert(t[i]);
        m[s[i]] = t[i];
    }
    return 1;
}

int main() { TimeMeasure _; __x();
    cout << sol("egg", "add") << endl; // 1
    cout << sol("foo", "bar") << endl; // 0
    cout << sol("paper", "title") << endl; // 1
    cout << sol("badc", "baba") << endl; // 0
    cout << sol("bbbaaaba", "aaabbbba") << endl; // 0
    cout << sol("egcd", "adfd") << endl; // 0
}
