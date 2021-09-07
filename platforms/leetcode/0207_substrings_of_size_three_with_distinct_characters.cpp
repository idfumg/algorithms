#include "../../template.hpp"

bool is_good(const string& s, const int i) {
    unordered_set<char> m;
    for (int j = 0; j < 3; ++j) {
        if (m.count(s[i + j])){
            return 0;
        }
        m.insert(s[i + j]);
    }
    return 1;
}

int sol(const string& s) {
    const int n = s.size();
    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (is_good(s, i)) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol("xyzzaz") << endl; // 1
    cout << sol("aababcabc") << endl; // 4
}
