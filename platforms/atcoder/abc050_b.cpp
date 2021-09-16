#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int n; is >> n;

    vector<int> times(n);
    int64_t total = 0;
    for (int i = 0; i < n; ++i) is >> times[i], total += times[i];

    int m; is >> m;
    for (int i = 0; i < m; ++i) {
        int p, x; is >> p >> x;
        int64_t current = total - times[p - 1] + x;
        cout << current << '\n';
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
3
2 1 4
2
1 1
2 3
)",
        R"(
5
7 2 3 8 5
3
4 2
1 7
4 13
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
