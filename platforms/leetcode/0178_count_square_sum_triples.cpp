#include "../../template.hpp"

int sol(const int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (i * i + j * j == k * k) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol(5) << endl; // 2
    cout << sol(10) << endl; // 4
}
