#include "../../template.hpp"

int sol(const string& s) {
    array<int, 32> chars{};
    for (const char ch : s) {
        ++chars[ch - 'a'];
    }
    int prev = -1;
    for (int i = 0; i < 32; ++i) {
        if (chars[i] > 0) {
            if (prev == -1) prev = chars[i];
            else if (chars[i] == prev) prev = chars[i];
            else return 0;
        }
    }
    return 1;
}

int main() { TimeMeasure _; __x();
    cout << sol("abacbc") << endl; // 1
    cout << sol("aaabb") << endl; // 0
    cout << sol("aca") << endl; // 0
}
