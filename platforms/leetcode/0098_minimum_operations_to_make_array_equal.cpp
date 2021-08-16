#include "../../template.hpp"

int tab(const int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        const int value = 2 * i + 1;
        if (value > n) {
            ans += value - n;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab(3) << endl; // 3
    cout << tab(4) << endl; // 4
    cout << tab(5) << endl; // 6
    cout << tab(6) << endl; // 9
    cout << tab(10) << endl; // 25
    cout << tab(999) << endl; // 249500
}
