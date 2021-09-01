#include "../../template.hpp"

vvi sol(const string& s) {
    const int n = s.size();
    int idx = 0;
    int count = 1;
    vvi ans;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
            if (i == n - 1 and count >= 3) {
                ans.push_back({idx, idx + count - 1});
            }
        }
        else {
            if (count >= 3) {
                ans.push_back({idx, idx + count - 1});
            }
            count = 1;
            idx = i;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("abbxxxxzzy") << endl; // [[3,6]]
    cout << sol("abcdddeeeeaabbbcd") << endl; // [[3,5],[6,9],[12,14]]
    cout << sol("aba") << endl; // []
    cout << sol("abc") << endl; // []
    cout << sol("aaaa") << endl; // []
}
