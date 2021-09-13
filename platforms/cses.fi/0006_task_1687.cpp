//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
//constexpr int INF = 1000000000 + 7;
using vi = vector<int>;
using vvi = vector<vi>;

vvi graph;
vvi up;

void binary_lifting(int at, int parent) {
    up[at][0] = parent;
    for (int k = 1; k < 20; ++k) {
        if (up[at][k - 1] == -1) up[at][k] = -1;
        else up[at][k] = up[up[at][k - 1]][k - 1];
    }
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        binary_lifting(adj, at);
    }
}

int query(int at, int jumps) {
    if (at == -1 or jumps == 0) return at;
    for (int i = 19; i >= 0; --i) {
        if (jumps >= (1 << i)) {
            return query(up[at][i], jumps - (1 << i));
        }
    }
    return -1;
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int q = 0; is >> q;
    graph = vvi(n + 1);
    up = vvi(n + 1, vi(20));
    for (int i = 2; i < n + 1; ++i) {
        int j = 0; is >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    binary_lifting(1, -1);
    for (int i = 0; i < q; ++i) {
        int node = 0; is >> node;
        int k = 0; is >> k;
        cout << query(node, k) << '\n';
    }
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
5 3
1 1 3 3
4 1
4 2
4 3
)";
    sol(input1); // 3 1 -1
    //sol(std::cin);
}
