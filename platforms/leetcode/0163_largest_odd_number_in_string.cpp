#include "../../template.hpp"

string sol(const string& s) {
    const int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if ((s[i] - '0') & 1) {
            return s.substr(0, i + 1);
        }
    }
    return "";
}

int main() { TimeMeasure _; __x();
    cout << sol("52") << endl; // 5
    cout << sol("4206") << endl; // ""
    cout << sol("35427") << endl; // 35427
}
