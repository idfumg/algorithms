#include "../../template.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
//const i32 INF = 1000000000 + 7;
const i32 fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();

i32 find(vector<i32>& parent, i32 i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent, parent[i]);
}

void join(vector<i32>& parent, i32 i, i32 j) {
    i = find(parent, i);
    j = find(parent, j);
    if (i == j) return;
    parent[i] = j;
}

string sol(string s, vector<vector<i32>> swaps) {
    i32 n = s.size();
    vector<i32> parent(n, -1);
    for (const auto& swap : swaps) {
        join(parent, swap[0], swap[1]);
    }
    unordered_map<i32, multiset<char>> groups;
    for (i32 i = 0; i < n; ++i) {
        i32 root = find(parent, i);
        groups[root].insert(s[i]);
    }
    string ans;
    for (i32 i = 0; i < n; ++i) {
        i32 root = find(parent, i);
        ans += *groups[root].begin();
        groups[root].erase(groups[root].begin());
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << sol("dcab", {{0,3},{1,2}}) << endl; // bacd
    cout << sol("dcab", {{0,3},{1,2},{0,2}}) << endl; // abcd
    cout << sol("cba", {{0,1},{1,2}}) << endl; // abc
}
