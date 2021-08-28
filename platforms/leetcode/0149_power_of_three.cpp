#include "../../template.hpp"

int sol(const int n) {
    if (n == 1) return 1;
    for (int factor = 3; factor <= n; factor *= 3) {
        if (factor == n) {
            return 1;
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol(27) << endl; // 1
    cout << sol(0) << endl; // 0
    cout << sol(9) << endl; // 1
    cout << sol(45) << endl; // 0
}
