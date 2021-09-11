#include "../../template.hpp"

bool is_lcs(const string& s, const string& t) {
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < s.size() and j < t.size()) {
        if (s[i] == t[j]) {
            ++j;
            ++i;
            ++count;
        }
        else {
            ++j;
        }
    }
    return count == s.size();
}

bool is_lus_for_each_word(const vs& words, const int i) {
    int n = words.size();
    for (int j = 0; j < n; ++j) {
        if (i != j and is_lcs(words[i], words[j])) {
            return false;
        }
    }
    return true;
}

int sol(const vs& words) {
    int n = words.size();
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (is_lus_for_each_word(words, i)) {
            ans = max(ans, (int)words[i].size());
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({"aba","cdc","eae"}) << endl; // 3
    cout << sol({"aaa","aaa","aa"}) << endl; // -1
}
