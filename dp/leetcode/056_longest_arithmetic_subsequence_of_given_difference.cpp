#include "../../template.hpp"

int tab(const vi& arr, const int k) {
    unordered_map<int, int> tab;
    int ans = 0;
    for (const int v : arr) {
        ans = max(ans, tab[v] = tab[v - k] + 1);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4}, 1) << endl; // 4
    cout << tab({1,3,5,7}, 1) << endl; // 1
    cout << tab({1,5,7,8,5,3,4,2,1}, -2) << endl; // 4
    cout << tab({1,5,7,8,5,3,4,2,1}, -2) << endl; // 4
}
