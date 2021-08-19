#include "../../template.hpp"

void Union(vi& parent, int i, int j) {
    if (parent[j] != -1) return;
    parent[j] = i;
}

vi tab(const vvi& arr, const int n) {
    vi parent(n, -1);
    for (const vi& edge : arr) {
        Union(parent, edge[0], edge[1]);
    }
    vi ans;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({{0,1},{0,2},{2,5},{3,4},{4,2}}, 6) << endl; // 0,3
    cout << tab({{0,1},{2,1},{3,1},{1,4},{2,4}}, 5) << endl; // 0,2,3
}
