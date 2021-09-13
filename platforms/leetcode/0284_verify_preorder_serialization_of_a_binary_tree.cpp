#include "../../template.hpp"

void read_number(const string& s, int& idx) {
    for (; idx < s.size() and s[idx] >= '0' and s[idx] <= '9'; ++idx) {
    }
}

bool sol(const string& s, int& idx) {
    if (idx >= s.size()) return false;
    if (s[idx] == '#') {
        ++idx;
        return true;
    }

    read_number(s, idx);
    if (not sol(s, ++idx)) return false;

    read_number(s, idx);
    if (not sol(s, ++idx)) return false;

    return true;
}

bool sol(const string& s) {
    int idx = 0;
    if (s[idx] == '#') return s.size() == 1;
    bool ans = sol(s, idx);
    return idx == s.size();
}

int main() { TimeMeasure _; __x();
    cout << sol("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl; // 1
    cout << sol("1,#") << endl; // 0
    cout << sol("9,#,#,1") << endl; // 0
    cout << sol("#") << endl; // 1
    cout << sol("#,#") << endl; // 0
    cout << sol("9,#,92,#,#") << endl; // 1
}
