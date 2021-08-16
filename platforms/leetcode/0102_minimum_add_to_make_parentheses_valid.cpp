#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++left;
        }
        else if (s[i] == '(' and right > 0) {
            ans += right;
            right = 0;
        }
        else if (s[i] == ')' and left > 0) {
            --left;
        }
        else if (s[i] == ')') {
            ++right;
        }
    }
    return left + right;
}

int main() { TimeMeasure _; __x();
    cout << tab("())") << endl; // 1
    cout << tab("(((") << endl; // 3
    cout << tab("()") << endl; // 0
    cout << tab("()))((") << endl; // 4
}
