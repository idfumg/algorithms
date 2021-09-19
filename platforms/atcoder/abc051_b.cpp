//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int n, s; is >> n >> s;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (s - i - j >= 0 and s - i - j <= n) {
                ++ans;
            }
        }
    }
    cout << ans;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
2 2
)",
        R"(
5 15
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
