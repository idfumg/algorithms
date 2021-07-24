#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    unordered_map<int, int> last;
    vi left(n, 0), right(n, n);
    for (int i = 0; i < n; ++i) {
        const int ch = s[i] - 'A';
        if (last.count(ch)) {
            left[i] = last[ch] + 1;
            right[last[ch]] = i;
        }
        last[ch] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((i + 1) - left[i]) * (right[i] - i);
    }
    return ans % MOD;
}

int tab2(const string& s) {
    const int n = s.size();
    vi L(n + 1), R(n + 1), left(27, 0), right(27, n + 1);
    for (int i = 1; i <= n; ++i) {
        L[i] = i - left[s[i - 1] - 'A'];
        left[s[i - 1] - 'A'] = i;
    }
    for (int i = n; i >= 1; --i) {
        R[i] = right[s[i - 1] - 'A'] - i;
        right[s[i - 1] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (L[i] * R[i]) % MOD;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ABC") << endl; // 10
    cout << tab("ABA") << endl; // 8
    cout << tab("LEETCODE") << endl; // 92
    cout << endl;
    cout << tab2("ABC") << endl; // 10
    cout << tab2("ABA") << endl; // 8
    cout << tab2("LEETCODE") << endl; // 92
}
