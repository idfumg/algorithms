#include "../../template.hpp"

int Find(vi& parent, const int i) {
    if (parent[i] == -1) return i;
    return parent[i] = Find(parent, parent[i]);
}

bool Union(vi& parent, const int i, const int j) {
    const int iroot = Find(parent, i);
    const int jroot = Find(parent, j);
    if (iroot == jroot) return false;
    parent[iroot] = jroot;
    return true;
}

bool sol(const vvi& edges, const int n) {
    vi parent(n, -1);
    for (const auto& edge : edges) {
        if (not Union(parent, edge[0], edge[1])) {
            return false;
        }
    }
    return count(parent.begin(), parent.end(), -1) == 1;
}

int main() { TimeMeasure _; __x();
    cout << sol({{0,1},{0,2},{0,3},{1,4}}, 5) << endl; // 1
    cout << sol({{0,1},{1,2},{2,3},{1,3},{1,4}}, 5) << endl; // 0
    cout << sol({{0,1},{2,3}}, 4) << endl; // 0
}
