#include "../../template.hpp"

int sol(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++ans;
        }
    }
    return ans == 3;
}

int main() { TimeMeasure _; __x();
    cout << sol(2) << endl; // 0
    cout << sol(4) << endl; // 1
}
