#include "../../template.hpp"

int Find(vi& parent, const int i) {
    if (parent[i] == -1) return i;
    return parent[i] = Find(parent, parent[i]);
}

void Union(vi& parent, const int i, const int j) {
    const int iroot = Find(parent, i);
    const int jroot = Find(parent, j);
    if (iroot == jroot) return;
    parent[iroot] = jroot;
}

int sol(const vvi& edges, const int n) {
    vi parent(n, -1);
    for (const auto& edge : edges) {
        Union(parent, edge[0], edge[1]);
    }
    return count(parent.begin(), parent.end(), -1);
}

int main() { TimeMeasure _; __x();
    cout << sol({{0,1},{1,2},{3,4}}, 5) << endl; // 2
    cout << sol({{0,1},{1,2},{2,3},{3,4}}, 5) << endl; // 1
}
