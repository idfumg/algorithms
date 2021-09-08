#include "../../template.hpp"

int sol(const vvi& arr, const int x, const int y) {
    const int n = arr.size();
    int ans = INF;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        const int a = arr[i][0];
        const int b = arr[i][1];
        if (a == x or b == y) {
            const int md = abs(x - a) + abs(y - b);
            if (md < ans) {
                ans = md;
                idx = i;
            }
        }
    }
    return idx;
}

int main() { TimeMeasure _; //__x();
    cout << sol({{1,2},{3,1},{2,4},{2,3},{4,4}}, 3, 4) << endl; // 2
    cout << sol({{3,4}}, 3, 4) << endl; // 0
    cout << sol({{2,3}}, 3, 4) << endl; // -1
    cout << sol({{1,2},{3,3},{3,3}}, 1, 1) << endl; // 0
}
