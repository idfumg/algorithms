#include "../../template.hpp"

vi tab(const vvi& arr, const int k) {
    const int n = arr.size();
    unordered_map<int, set<int>> times;
    for (const vi& id_time : arr) {
        times[id_time[0]].insert(id_time[1]);
    }
    vi ans(k);
    for (const auto& [id, uam] : times) {
        ++ans[uam.size() - 1];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({{0,5},{1,2},{0,2},{0,5},{1,3}}, 5) << endl; // 0 2 0 0 0
    cout << tab({{1,1},{2,2},{2,3}}, 4) << endl; // 1 1 0 0
}
