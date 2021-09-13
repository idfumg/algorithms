#include "../../template.hpp"

ll sol_(const ll m, const ll n, const ll moves, const ll x, const ll y, vvvll& memo) {
    if (x < 0 or y < 0 or x > m or y > n) return 1;
    if (moves == 0) return 0;
    if (memo[x][y][moves] != INF) return memo[x][y][moves];

    return memo[x][y][moves] =
        (sol_(m, n, moves - 1, x - 1, y, memo) % 1000000007 +
        sol_(m, n, moves - 1, x + 1, y, memo) % 1000000007 +
        sol_(m, n, moves - 1, x, y - 1, memo) % 1000000007 +
        sol_(m, n, moves - 1, x, y + 1, memo) % 1000000007) % 1000000007;
}

ll sol(const ll m, const ll n, const ll moves, const ll x, const ll y) {
    vvvll memo(m + 2, vvll(n + 2, vll(moves + 1, INF)));
    return sol_(m - 1, n - 1, moves, x, y, memo);
}

int main() { TimeMeasure _; __x();
    cout << sol(2, 2, 2, 0, 0) << endl; // 6
    cout << sol(1, 3, 3, 0, 1) << endl; // 12
}
