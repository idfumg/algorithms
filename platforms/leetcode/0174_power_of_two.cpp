#include "../../template.hpp"

int sol(const int n) {
    if (n == 0) return 0;
    return pow(2, (int)log2(n)) == n;
}

int main() { TimeMeasure _; __x();
    cout << sol(1) << endl; // 1
    cout << sol(16) << endl; // 1
    cout << sol(3) << endl; // 0
    cout << sol(4) << endl; // 1
    cout << sol(5) << endl; // 0
    cout << sol(0) << endl; // 0
}
