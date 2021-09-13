#include "../../template.hpp"

int sol(const string& s, const int i, const int j, const int mask) {
    if (i > j) {
        return 0;
    }

    if (i == j) {
        return not (mask & (1 << i));
    }

    if (s[i] == s[j] and not (mask & (1 << i)) and not (mask & (1 << j))) {
        return 2 + sol(s, i + 1, j - 1, mask);
    }

    return max(sol(s, i + 1, j, mask), sol(s, i, j - 1, mask));
}

bool IsPalindrome(const string& s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int sol(const string& s) {
    const int n = s.size();
    vector<tuple<int, int>> masks;
    for (int i = 1; i < (1 << n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                temp.push_back(s[j]);
            }
        }
        if (IsPalindrome(temp)) {
            masks.push_back({i, (int)temp.size()});
        }
    }
    int ans = 0;
    for (const auto [mask, count] : masks) {
        ans = max(ans, count * sol(s, 0, s.size() - 1, mask));
    }
    return ans;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol("ababbb") << endl; // 9
    cout << sol("zaaaxbbby") << endl; // 9
}
