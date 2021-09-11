#include "../../template.hpp"

int sol(const vvi& arr) {
    const int n = arr.size();
    if (n < 3) return 1;

    const int x0 = arr[0][0];
    const int y0 = arr[0][1];
    const int x1 = arr[1][0];
    const int y1 = arr[1][1];

    for (int i = 2; i < n; ++i) {
        const int x2 = arr[i][0];
        const int y2 = arr[i][1];
        if ((y1 - y0) * (x2 - x0) != (y2 - y0) * (x1 - x0)) {
            return 0;
        }
    }
    return 1;
}

int main() { TimeMeasure _; __x();
    cout << sol({{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}) << endl; // 1
    cout << sol({{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}) << endl; // 0
    cout << sol({{1,2},{2,3}}) << endl; // 1
    cout << sol({{0,0},{0,1},{0,-1}}) << endl; // 1
    cout << sol({{1,2},{2,3},{3,5}}) << endl; // 0
}
