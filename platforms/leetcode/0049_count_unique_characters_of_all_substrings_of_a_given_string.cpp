#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    unordered_map<int, int> prev;
    vi left(n, 0), right(n, n);
    for (int i = 0; i < n; ++i) {
        const int ch = s[i] - 'A';
        if (prev.count(ch)) {
            left[i] = prev[ch] + 1;
            right[prev[ch]] = i;
        }
        prev[ch] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (i + 1 - left[i]) * (right[i] - i);
    }
    return ans % MOD;
}

int tab(const string& s) {
    const int n = s.size();
    array<int, 32> prev{};
    for (int i = 0; i < prev.size(); ++i) {
        prev[i] = -1;
    }
    vi left(n, 0);
    vi right(n, n - 1);
    for (int i = 0; i < n; ++i) {
        const char ch = s[i] - 'A';
        if (prev[ch] != -1) {
            left[i] = prev[ch] + 1;
            right[prev[ch]] = i - 1;
        }
        prev[ch] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (i - left[i] + 1) * (right[i] - i + 1);
    }
    return ans;
}

int tab3(const string& s) {
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

int tab4(const string& s) {
    const int n = s.size();
    array<int, 27> left, right;
    for (int i = 0; i < 27; ++i) {
        left[i] = 0;
        right[i] = n + 1;
    }
    vi L(n + 1), R(n + 1);
    for (int i = 1; i <= n; ++i) {
        {
            const int ch = s[i - 1] - 'A';
            L[i] = i - left[ch];
            left[ch] = i;
        }
        {
            const int ch = s[n - i] - 'A';
            R[n - i + 1] = right[ch] - (n - i + 1);
            right[ch] = n - i + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += L[i] * R[i];
        ans %= MOD;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ABC") << endl; // 10
    cout << tab("ABA") << endl; // 8
    cout << tab("LEETCODE") << endl; // 92
    cout << endl;
    cout << tab2("ABC") << endl; // 10 // tab optimization
    cout << tab2("ABA") << endl; // 8
    cout << tab2("LEETCODE") << endl; // 92
    cout << endl;
    cout << tab3("ABC") << endl; // 10
    cout << tab3("ABA") << endl; // 8
    cout << tab3("LEETCODE") << endl; // 92
    cout << endl;
    cout << tab4("ABC") << endl; // 10 // tab3 optimization
    cout << tab4("ABA") << endl; // 8
    cout << tab4("LEETCODE") << endl; // 92
}
