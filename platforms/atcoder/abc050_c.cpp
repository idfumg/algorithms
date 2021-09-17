//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

template<class T>
T power_mod(T base, T p, const T mod) {
    T res = 1;
    while (p > 0) {
        if (p & 1) res *= base, --p, res %= mod;
        else base *= base, p /= 2, base %= mod;
    }
    return res;
}

void sol(istream& is) {
    int64_t n; is >> n;
    vector<int64_t> count(n + 1);
    for (int i = 0; i < n; ++i) {
        int64_t diff; is >> diff;
        ++count[diff];
        if (diff != 0 and count[diff] > 2) {
            cout << 0;
            return;
        }
        if (diff == 0 and count[0] > 1) {
            cout << 0;
            return;
        }
    }
    if (n & 1) {
        if (count[0] != 1) {
            cout << 0;
            return;
        }
        for (int i = 2; i < n; i += 2) {
            if (count[i] != 2) {
                cout << 0;
                return;
            }
        }
    }
    else {
        for (int i = 1; i < n; i += 2) {
            if (count[i] != 2) {
                cout << 0;
                return;
            }
        }
    }
    cout << power_mod<int64_t>(2, n / 2, 1e9 + 7);
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
5
2 4 4 0 2
)",
        R"(
7
6 4 0 2 4 0 2
)",
        R"(
8
7 5 1 1 7 3 5 3
)"
    };

    for (const auto& input : inputs) {
        istringstream is(input);
        sol(is);
        cout << endl;
    }
}

#else

int main() {
    sol(std::cin);
}

#endif // LOCAL_MACHINE
