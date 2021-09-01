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
    int n; cin >> n;
    unordered_set<string> memo;
    for (int i = 0; i < n; ++i) {
        string firstname, lastname; cin >> firstname >> lastname;
        const string s = firstname + ' ' + lastname;
        if (memo.count(s)) {
            cout << "Yes";
            return 0;
        }
        memo.insert(s);
    }
    cout << "No";
    return 0;
}
