#include "../../template.hpp"

int sol(const vi& arr) {
    unordered_set<int> memo;
    for (int i = 0; i < arr.size(); ++i) {
        if (memo.count(arr[i])) return arr[i];
        memo.insert(arr[i]);
    }
    return arr.size() + 1;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,3,4,2,2}) << endl; // 2
    cout << sol({3,1,3,4,2}) << endl; // 3
    cout << sol({1,1}) << endl; // 1
    cout << sol({1,1,2}) << endl; // 1
}
