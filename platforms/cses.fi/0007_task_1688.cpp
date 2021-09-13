//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
//constexpr int INF = 1000000000 + 7;
using vi = vector<int>;
using vvi = vector<vi>;

vvi graph;
vvi up;
vi levels;

void gen_levels(int at, int parent, int level = 0) {
    levels[at] = level;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        gen_levels(adj, at, 1 + level);
    }
}

void binary_lifting(int at, int parent) {
    up[at][0] = parent;
    for (int i = 1; i < 20; ++i) {
        if (up[at][i - 1] == -1) up[at][i] = -1;
        else up[at][i] = up[up[at][i - 1]][i - 1];
    }
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        binary_lifting(adj, at);
    }
}

int lift_node(int at, int k) {
    for (int i = 19; i >= 0; --i) {
        if (at == -1 or k == 0) {
            break;
        }
        if (k >= (1 << i)) {
            at = up[at][i];
            k -= (1 << i);
        }
    }
    return at;
}

int FindLCA(int u, int v) {
    if (levels[u] < levels[v]) swap(u, v);
    u = lift_node(u, levels[u] - levels[v]);
    int low = 0, high = levels[u];
    while (low != high) {
        int mid = low + (high - low) / 2;
        int x1 = lift_node(u, mid);
        int x2 = lift_node(v, mid);
        if (x1 == x2) high = mid;
        else low = mid + 1;
    }
    return lift_node(u, low);
}

int FindLCA2(int u, int v) {
    if (levels[u] < levels[v]) swap(u, v);
    u = lift_node(u, levels[u] - levels[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int q = 0; is >> q;
    graph = vvi(n + 1);
    up = vvi(n + 1, vi(20));
    levels = vi(n + 1);
    for (int i = 2; i <= n; ++i) {
        int j = 0; is >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    gen_levels(1, -1, 0);
    binary_lifting(1, -1);
    for (int i = 0; i < q; ++i) {
        int a = 0; is >> a;
        int b = 0; is >> b;
        cout << FindLCA2(a, b) << '\n';
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
4 5
2 5
1 4
)";
    //sol(input1); // 3 1 1
    sol(std::cin);
}
