//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    uint64_t a, b, x; is >> a >> b >> x;
    uint64_t count = (b / x) - (a / x) + (a % x == 0);
    cout << count;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
4 8 2
)",
        R"(
0 5 1
)",
        R"(
9 9 2
)",
        R"(
1 1000000000000000000 3
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
