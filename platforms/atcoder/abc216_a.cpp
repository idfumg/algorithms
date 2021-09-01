//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF static_cast<int32_t>(1e9)

using ll = int64_t;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;

[[maybe_unused]] static const auto ___x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

int main() {
    string s; cin >> s;
    int x = 0;
    int i = 0;
    int n = s.size();
    for (; i < n; ++i) {
        if (s[i] == '.') {
            ++i;
            break;
        }
        else {
            x = x * 10 + (s[i] - '0');
        }
    }
    int y = 0;
    for (; i < n; ++i) {
        y = y * 10 + (s[i] - '0');
    }
    cout << x;
    if (y >= 0 and y <= 2) cout << '-';
    else if (y >= 3 and y <= 6) {}
    else cout << '+';
}
