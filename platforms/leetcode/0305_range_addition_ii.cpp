#include "../../template.hpp"

int sol(const int m, const int n, const vvi& ops) {
    int minx = m;
    int miny = n;
    for (const auto& op : ops) {
        minx = min(minx, op[0]);
        miny = min(miny, op[1]);
    }
    return minx * miny;
}

int main() { TimeMeasure _; __x();
    cout << sol(3, 3, {{2,2},{3,3}}) << endl; // 4
    cout << sol(3, 3, {{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}}) << endl; // 4
    cout << sol(3, 3, {}) << endl; // 9
}
