#include "../../template.hpp"

int tab(const int n, int k) {
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if (--k == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << tab(12, 3) << endl; // 3
    cout << tab(7, 2) << endl; // 7
    cout << tab(4, 4) << endl; // -1
    cout << tab(1, 1) << endl; // 1
    cout << tab(1000, 3) << endl; // 4
}
