#include "../../template.hpp"

int tab(const vi& arr) {
    const unordered_set<int> exists(cbegin(arr), cend(arr));
    int ans = not arr.empty();
    for (const int elem : arr) {
        if (not exists.count(elem - 1)) {
            for (int count = 1; exists.count(elem + count); ++count) {
                ans = max(ans, count + 1);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({100,4,200,1,3,2}) << endl; // 4
    cout << tab({0,3,7,2,5,8,4,6,0,1}) << endl; // 9
}
