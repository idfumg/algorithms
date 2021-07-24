#include "../../template.hpp"

bool rec(int n, int x, int y, bool isa) {
    if (n == 0 and not isa) return true;
    if (n == 0 and isa) return false;
    if (n <= 0) return false;
    return
        rec(n - x, x, y, not isa) or
        rec(n - y, x, y, not isa) or
        rec(n - 1, x, y, not isa);
}

char rec(int n, int x, int y) {
    return rec(n, x, y, true) ? 'A' : 'B';
}

char tab(int n, int x, int y) {
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (i == 0 and not j) dp[i][j] = true;
            else if (i == 0 and j) dp[i][j] = false;
            else {
                if (i >= x and dp[i - x][not j]) dp[i][j] = true;
                if (i >= y and dp[i - y][not j]) dp[i][j] = true;
                if (i >= 1 and dp[i - 1][not j]) dp[i][j] = true;
            }
        }
    }
    return dp[n][1] ? 'A' : 'B';
}

int main() { TimeMeasure _; __x();
    int n1 = 5, x1 = 3, y1 = 4;
    int n2 = 2, x2 = 3, y2 = 4;
    cout << rec(n1, x1, y1) << endl; // A
    cout << rec(n2, x2, y2) << endl; // B
    cout << tab(n1, x1, y1) << endl; // A
    cout << tab(n2, x2, y2) << endl; // B
}
