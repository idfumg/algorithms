#include "../../template.hpp"

string sol(const string& s) {
    const int n = s.size();
    string ans;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            ans += s[i - 1] + (s[i] - '0');
        }
        else {
            ans += s[i];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("a1c1e1") << endl; // abcdef
    cout << sol("a1b2c3d4e") << endl; // abbdcfdhe
}
