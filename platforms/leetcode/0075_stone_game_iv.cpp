#include "../../template.hpp"

int rec(const int n) {
    if (n == 0) return 0;

    for (int i = 1; i * i <= n; ++i) {
        if (rec(n - i * i) == 0) {
            return 1;
        }
    }

    return 0;
}

int tab(const int n) {
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (dp[i - j * j] == 0) dp[i] = 1;
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec(1) << endl; // 1
    cout << rec(2) << endl; // 0
    cout << rec(3) << endl; // 1
    cout << rec(4) << endl; // 1
    cout << rec(7) << endl; // 0
    cout << rec(17) << endl; // 0
    cout << rec(15) << endl; // 0
    cout << endl;
    cout << tab(1) << endl; // 1
    cout << tab(2) << endl; // 0
    cout << tab(3) << endl; // 1
    cout << tab(4) << endl; // 1
    cout << tab(7) << endl; // 0
    cout << tab(17) << endl; // 0
    cout << tab(15) << endl; // 0
}
