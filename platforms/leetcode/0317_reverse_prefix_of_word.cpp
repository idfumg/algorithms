#include "../../template.hpp"

string sol(string s, char ch) {
    const int idx = s.find(ch);
    if (idx == string::npos) return s;
    reverse(s.begin(), s.begin() + idx + 1);
    return s;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol("abcdefd", 'd') << endl; // dcbaefd
    cout << sol("xyxzxe", 'z') << endl; // zxyxxe
    cout << sol("abcd", 'z') << endl; // abcd
}
