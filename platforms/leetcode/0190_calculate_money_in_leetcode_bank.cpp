#include "../../template.hpp"

int sol(int n) {
    int weeks = n / 7;
    int days = n % 7;
    int k = 1;
    int ans = 0;
    for (int i = 1; i <= weeks; ++i) {
        ans += (i + 7 - 1) * (7 + i) / 2;
        ans -= (i) * (i + 1) / 2;
        ans += i;
    }
    ans += (weeks + days) * (weeks + days + 1) / 2;
    ans -= (weeks + 1) * (weeks + 1 + 1) / 2;
    ans += weeks + 1;
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol(4) << endl; // 10
    cout << sol(10) << endl; // 37
    cout << sol(20) << endl; // 96
}
