#include "../../template.hpp"

int sol(int n, const int k) {
    int x = 0;
    while (n > 0) {
        x = x * 10 + (n % k);
        n /= k;
    }

    int ans = 0;
    for (; x > 0; x /= 10) {
        ans += x % 10;
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol(34, 6) << endl; // 9
    cout << sol(10, 10) << endl; // 1
    cout << sol(68, 2) << endl; // 2
}
