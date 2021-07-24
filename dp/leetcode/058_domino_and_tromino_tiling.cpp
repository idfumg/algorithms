#include "../../template.hpp"

constexpr int M = 1e9 + 7;

int rec(int n);

int g(int n) {
    if (n <= 1) return n;
    return g(n - 1) + rec(n - 1);
}

int rec(int n) {
    if (n <= 2) return n;
    return rec(n - 1) + rec(n - 2) + 2 * g(n - 2);
}

int tab(int n) {
    vi f(n + 3), g(n + 3);
    f[0] = g[0] = 0;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    for (int i = 3; i <= n; ++i) {
        g[i] = g[i - 1] + f[i - 1];
        g[i] %= M;
        f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 2];
        f[i] %= M;
    }
    return f[n];
}

int main() { TimeMeasure _; __x();
    cout << rec(4) << endl; // 11
    cout << rec(5) << endl; // 24
    cout << rec(6) << endl; // 53
    cout << endl;
    cout << tab(4) << endl; // 11
    cout << tab(5) << endl; // 24
    cout << tab(6) << endl; // 53
    cout << tab(1) << endl; // 1
}
