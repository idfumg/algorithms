#include "../../template.hpp"

vi sol(const vi& arr) {
    unordered_map<int, int> memo;
    for (const int value : arr) ++memo[value];
    vi ans;
    for (const auto& [value, count] : memo) {
        if (count == 2) {
            ans.push_back(value);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({4,3,2,7,8,2,3,1}) << endl; // 2,3
    cout << sol({1,1,2}) << endl; // 1
    cout << sol({1}) << endl; // []
}
