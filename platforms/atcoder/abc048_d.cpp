//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    string s; is >> s;
    int n = s.size();
    if (s.front() == s.back()) {
        if (n & 1) cout << "Second";
        else cout << "First";
    }
    else {
        if (n & 1) cout << "First";
        else cout << "Second";
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
aba
)",
        R"(
abc
)",
        R"(
abcab
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
