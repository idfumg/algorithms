#include "../../template.hpp"

int sol(const string& s) {
    const int n = s.size();
    int idx = -1;
    for (int i = n - 1; i > 0; --i) {
        if (s[i] == '1') {
            idx = i;
            break;
        }
    }
    for (int i = idx; i > 0; --i) {
        if (s[i] == '0') {
            return 0;
        }
    }
    return 1;
}

int main() { TimeMeasure _; //__x();
    cout << sol("1001") << endl; // 0
    cout << sol("110") << endl; // 1
    cout << sol("10") << endl; // 1
    cout << sol("1100111") << endl; // 0
}
