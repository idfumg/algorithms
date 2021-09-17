#include "../../template.hpp"

vi sol(int n) {
    vi is_prime(n + 1, -1);
    is_prime[1] = 1;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p] == -1) {
            for (int i = p * p; i <= n; i += p) {
                if (is_prime[i] == -1) {
                    is_prime[i] = p;
                }
            }
            is_prime[p] = p;
        }
    }
    vi ans;
    for (int i = 1; i <= n; ++i) {
        ans.push_back(is_prime[i]);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << sol(6) << endl; // 1 2 3 2 5 2
}
