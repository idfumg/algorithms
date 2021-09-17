#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int h, w; is >> h >> w;
    vector<char> row(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) is >> row[j];
        for (int j = 0; j < w; ++j) cout << row[j]; cout << '\n';
        for (int j = 0; j < w; ++j) cout << row[j]; cout << '\n';
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
2 2
*.
.*
)",
        R"(
1 4
***.
)",
        R"(
9 20
.....***....***.....
....*...*..*...*....
...*.....**.....*...
...*.....*......*...
....*.....*....*....
.....**..*...**.....
.......*..*.*.......
........**.*........
.........**.........
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
