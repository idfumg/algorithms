#include "../../template.hpp"

bool sol(const ll n) {
    for (ll i = 0; i * i <= n; ++i) {
        const ll b2 = abs(n - i * i);
        const ll b = sqrt(b2);
        if (n - b * b == i * i) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _; __x();
    cout << sol(5) << endl; // 1
    cout << sol(3) << endl; // 0
    cout << sol(4) << endl; // 1
    cout << sol(2) << endl; // 1
    cout << sol(1) << endl; // 1
    cout << sol(6) << endl; // 0
    cout << sol(12) << endl; // 0
    cout << sol(0) << endl; // 1
    cout << sol(999999999) << endl; // 0
}
