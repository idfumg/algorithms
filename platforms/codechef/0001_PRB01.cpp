//#include "../../template.hpp"

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void sol(istream& is = std::cin) {
    int T; is >> T;
    while (T--) {
        int n; is >> n;
        cout << (is_prime(n) ? "yes" : "no") << '\n';
    }
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
5
23
13
20
1000
99991
)";
    sol(input1);
}

// int main() {
//     sol(std::cin);
// }
