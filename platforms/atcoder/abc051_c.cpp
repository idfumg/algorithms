//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int sx, sy, tx, ty; is >> sx >> sy >> tx >> ty;
    tx -= sx;
    ty -= sy;
    string ans = "";
    for(int i = 0; i < ty; i++) ans = ans + 'U';
    for(int i = 0; i < tx; i++) ans = ans + 'R';
    for(int i = ty; i > 0; i--) ans = ans + 'D';
    for(int i = tx; i > 0; i--) ans = ans + 'L';
    ans = ans + 'L';
    for(int i = 0; i < ty+1; i++) ans = ans + 'U';
    for(int i = 0; i < tx+1; i++) ans = ans + 'R';
    ans = ans + 'D' + 'R';
    for(int i = ty+1; i > 0; i--) ans = ans + 'D';
    for(int i = tx+1; i > 0; i--) ans = ans + 'L';
    ans = ans + 'U';
    cout << ans << endl;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
0 0 1 2
)",
        R"(
-2 -2 1 1
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
