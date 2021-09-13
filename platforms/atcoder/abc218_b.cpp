#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is = std::cin) {
    for (int i = 0; i < 26; ++i) {
        int ch; is >> ch;
        cout << (char)(ch - 1 + 'a');
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
)",
        R"(
5 11 12 16 25 17 18 1 7 10 4 23 20 3 2 24 26 19 14 9 6 22 8 13 15 21
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
