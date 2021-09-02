#include "../../template.hpp"

string sol(string s) {
    bool skipped = true;
    while (skipped and s.size() >= 2) {
        skipped = false;
        string temp;
        for (int i = 0; i < s.size(); ++i) {
            if (not skipped and i + 1 < s.size() and s[i] != s[i + 1] and tolower(s[i]) == tolower(s[i + 1])) {
                i += 1;
                skipped = true;
            }
            else {
                temp += s[i];
            }
        }
        s = temp;
    }
    return s;
}

int main() { TimeMeasure _; __x();
    cout << sol("leEeetcode") << endl; // leetcode
    cout << sol("abBAcC") << endl; // ""
    cout << sol("s") << endl; // s
    cout << sol("Pp") << endl; // ""
}
