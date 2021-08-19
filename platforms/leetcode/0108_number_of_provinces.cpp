#include "../../template.hpp"

int Find(vi& parent, vi& rank, int i) {
    int root = i, prev = i;
    for (; parent[root] != -1; root = parent[root]);
    for (i = parent[i]; i != -1; prev = i, i = parent[i]) parent[prev] = root;
    rank[root] = 1;
    return root;
}

void Union(vi& parent, vi& rank, const int i, const int j) {
    const int iroot = Find(parent, rank, i);
    const int jroot = Find(parent, rank, j);
    if (iroot == jroot) return;
    const int irank = rank[i];
    const int jrank = rank[j];
    if (irank < jrank) {
        parent[iroot] = jroot;
    }
    else if (irank > jrank) {
        parent[jroot] = iroot;
    }
    else {
        parent[iroot] = jroot;
        ++rank[jroot];
    }
}

int tab(const vvi& mat) {
    const int n = mat.size();
    vi parent(n, -1), rank(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (mat[i][j] == 1) Union(parent, rank, i, j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    const vvi tab1 = {{1,1,0},{1,1,0},{0,0,1}};
    const vvi tab2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << tab(tab1) << endl; // 2
    cout << tab(tab2) << endl; // 3
}
