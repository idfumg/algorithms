#include "../../template.hpp"

int sol(const vvi& mat) {
    const int m = mat.size();
    const int n = reduce(mat[0].begin(), mat[0].end());
    unordered_map<int, int> count;
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (const int value : mat[i]) {
            sum += value;
            ++count[sum];
        }
    }
    int ans = m;
    for (const auto& [value, c] : count) {
        if (value != n) {
            ans = min(ans, m - c);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}}) << endl; // 2
    cout << sol({{1},{1},{1}}) << endl; // 3
    cout << sol({{100000000,100000000},{100000000,100000000}}) << endl; // 0
}
