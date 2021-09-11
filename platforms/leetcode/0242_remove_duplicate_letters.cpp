#include "../../template.hpp"

string sol(const string& s) {
    array<int, 26> count{};
    for (const char ch : s) {
        ++count[ch - 'a'];
    }
    array<int, 26> used{};
    string ans;
    for (const char ch : s) {
        --count[ch - 'a'];
        if (used[ch - 'a']) continue;
        while (not ans.empty() and ch < ans.back() and count[ans.back() - 'a'] > 0) {
            used[ans.back() - 'a'] = 0;
            ans.pop_back();
        }
        ans.push_back(ch);
        used[ch - 'a'] = 1;
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol("bcabc") << endl; // "abc"
    cout << sol("cbacdcbc") << endl; // "acdb"
}
