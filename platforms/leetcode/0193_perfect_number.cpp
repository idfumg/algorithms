#include "../../template.hpp"

int sol(const int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() { TimeMeasure _; __x();
    cout << sol(28) << endl; // 1
    cout << sol(6) << endl; // 1
    cout << sol(496) << endl; // 1
    cout << sol(8128) << endl; // 1
    cout << sol(2) << endl; // 0
}
