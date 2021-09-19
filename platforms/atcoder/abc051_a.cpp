//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    char ch;
    while (is >> ch) {
        if (ch == ',') cout << ' ';
        else cout << ch;
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
happy,newyear,enjoy
)",
        R"(
haiku,atcoder,tasks
)",
        R"(
abcde,fghihgf,edcba
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
