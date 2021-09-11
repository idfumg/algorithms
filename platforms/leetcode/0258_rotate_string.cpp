#include "../../template.hpp"

bool is_equals(const string& s, const string& t, int i) {
    int n = t.size();
    for (int j = 0; j < n; ++j, ++i) {
        if (s[i % n] != t[j]) {
            return false;
        }
    }
    return true;
}

bool sol(const string& s, const string& t) {
    if (s.size() != t.size()) return 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (is_equals(s, t, i)) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _; __x();
    cout << sol("abcde", "cdeab") << endl; // 1
    cout << sol("abcde", "abced") << endl; // 0
}
