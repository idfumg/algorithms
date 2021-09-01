#include "../../template.hpp"

int sol(const string& s, const string& broken_) {
    const unordered_set<char> broken(broken_.begin(), broken_.end());
    const int n = s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (broken.count(s[i])) while (i < n and s[i] != ' ') ++i;
        else if ((i < n and s[i] == ' ') or i == n - 1) ++count;
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << sol("hello world", "ad") << endl; // 1
    cout << sol("leet code", "lt") << endl; // 1
    cout << sol("leet code", "e") << endl; // 0
}
