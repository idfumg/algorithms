#include "../../template.hpp"

vvi tab(const vi& arr) {
    unordered_map<int, vi> groups;
    const int n = arr.size();
    vvi ans;
    for (int i = 0; i < n; ++i) {
        const int value = arr[i];
        groups[value].push_back(i);
        if (groups[value].size() == value) {
            ans.push_back(groups[value]);
            groups[value].clear();
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({3,3,3,3,3,1,3}) << endl;
    cout << tab({2,1,3,3,3,2}) << endl;
}
