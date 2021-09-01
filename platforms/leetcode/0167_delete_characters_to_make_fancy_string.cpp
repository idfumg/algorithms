#include "../../template.hpp"

string sol(const string& s) {
    string ans;
    int count = 1;
    const int n = s.size();
    ans.push_back(s[0]);
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            if (count == 2) continue;
            else ++count;
        }
        else {
            count = 1;
        }
        ans.push_back(s[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("leeetcode") << endl; // leetcode
    cout << sol("aaabaaaa") << endl; // aabaa
    cout << sol("aab") << endl; // aab
}
