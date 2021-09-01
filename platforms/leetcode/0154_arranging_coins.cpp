#include "../../template.hpp"

int sol(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    for (int i = 0; i <= n; ++i) {
        if ((i * (i + 1) / 2) > n) {
            return i - 1;
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol(5) << endl; // 2
    cout << sol(8) << endl; // 3
    cout << sol(1) << endl; // 1
    cout << sol(2) << endl; // 1
}
