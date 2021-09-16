#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int a, b; char op; is >> a >> op >> b;
    if (op == '+') cout << a + b;
    else cout << a - b;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
1 + 2
)",
        R"(
5 - 7
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
