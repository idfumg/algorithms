#include "../../template.hpp"

vi sol(int n) {
    vi ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << sol(10) << endl; // 1 10 2 5
    cout << sol(100) << endl; // 1 100 2 50 4 25 5 20 10
    cout << sol(125) << endl; // 1 125 5 25
}
