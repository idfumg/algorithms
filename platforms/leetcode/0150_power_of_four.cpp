#include "../../template.hpp"

int sol(const int n) {
    if (n == 1) return 1;
    for (int factor = 4; factor <= n; factor *= 4) {
        if (factor == n) {
            return 1;
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol(16) << endl; // 1
    cout << sol(5) << endl; // 0
    cout << sol(1) << endl; // 1
}
