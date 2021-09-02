#include "../../template.hpp"

int sol(int n) {
    return n == 0 ? 0 : n / 5 + sol(n / 5);
}

int main() { TimeMeasure _; __x();
    cout << sol(3) << endl; // 0
    cout << sol(5) << endl; // 1
    cout << sol(0) << endl; // 0
    cout << sol(10) << endl; // 2
    cout << sol(8) << endl; // 1
    cout << sol(13) << endl; // 2
}
