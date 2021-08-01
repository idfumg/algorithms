#include "../../template.hpp"

int rec(const string& s, const int x, const int y, const int n) {
    if (n >= s.size() - 1) return 1;
    for (int k = x; k <= y; ++k) {
        if (n + k < s.size() and s[n + k] == '0') {
            if (rec(s, x, y, n + k)) {
                return 1;
            }
        }
    }
    return 0;
}

int rec(const string& s, const int x, const int y) {
    return rec(s, x, y, 0);
}

int tab(const string& s, const int x, const int y) {
    const int n = s.size();
    vi dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int k = x; k <= y; ++k) {
            if (i + k < n and s[i + k] == '0') {
                if (dp[i + k] == 1) {
                    dp[i] = 1;
                }
            }
        }
    }
    return dp[0];
}

int tab2(const string& s, const int x, const int y) {
    const int n = s.size();
    vi dp(n);
    dp[0] = 1;
    multiset<int> window = {dp[0]};
    for (int i = x; i < n; ++i) {
        if (i - y - 1 >= 0) window.erase(window.find(dp[i - y - 1]));
        if (not window.empty() and s[i] == '0') dp[i] = *window.crbegin();
        window.insert(dp[i - x + 1]);
    }
    return dp[n - 1];
}

int main() { TimeMeasure _; __x();
    cout << rec("011010", 2, 3) << endl; // 1
    cout << rec("01101110", 2, 3) << endl; // 0
    cout << rec("00111010", 3, 5) << endl; // 0
    cout << rec("00", 1, 1) << endl; // 1
    cout << endl;
    cout << tab("011010", 2, 3) << endl; // 1
    cout << tab("01101110", 2, 3) << endl; // 0
    cout << tab("00111010", 3, 5) << endl; // 0
    cout << tab("00", 1, 1) << endl; // 1
    cout << endl;
    cout << tab2("011010", 2, 3) << endl; // 1
    cout << tab2("01101110", 2, 3) << endl; // 0
    cout << tab2("00111010", 3, 5) << endl; // 0
    cout << tab2("00", 1, 1) << endl; // 1
}
