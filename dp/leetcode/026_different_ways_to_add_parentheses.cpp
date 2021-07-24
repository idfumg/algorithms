#include "../../template.hpp"

static bool is_op(const char ch) noexcept {
    return ch == '-' or ch == '+' or ch == '*';
}

static int apply_op(const char ch, const int a, const int b) noexcept {
    if (ch == '-') return a - b;
    if (ch == '+') return a + b;
    return a * b;
}

vi rec(const string& s) noexcept {
    vi ways;
    for (int i = 0; i < s.size(); ++i) {
        if (is_op(s[i])) {
            for (const int value1 : rec(s.substr(0, i))) {
                for (const int value2 : rec(s.substr(i + 1))) {
                    ways.push_back(apply_op(s[i], value1, value2));
                }
            }
        }
    }
    return not ways.empty() ? ways : vi{stoi(s)};
}

int main() { TimeMeasure _; __x();
    cout << rec("2-1-1") << endl; // 0,2
    cout << rec("2*3-4*5") << endl; // -34,-14,-10,-10,10
}
