#include "../../template.hpp"

int sol(const string& s) {
    array<int, 32> chars{};
    for (const char ch : s) {
        ++chars[ch - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (chars[i] == 0) return 0;
    }
    return 1;
}

int main() { TimeMeasure _; //__x();
    cout << sol("thequickbrownfoxjumpsoverthelazydog") << endl; // 1
    cout << sol("leetcode") << endl; // 0
}
