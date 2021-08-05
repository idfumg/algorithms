#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    vi digits(10, 0);
    for (const char ch : s) {
        if (ch >= '0' and ch <= '9') {
            digits[ch - '0'] = 1;
        }
    }
    bool found = false;
    for (int i = 9; i >= 0; --i) {
        if (digits[i]) {
            if (not found) {
                found = true;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << tab("dfa12321afd") << endl; // 2
    cout << tab("abc1111") << endl; // -1
    cout << tab("ck077") << endl; // 0
}
