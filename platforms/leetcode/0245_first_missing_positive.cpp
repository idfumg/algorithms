#include "../../template.hpp"

int sol(vi nums) {
    unordered_set<int> counts(nums.begin(), nums.end());;
    int i = 1;
    while (counts.count(i)) ++i;
    return i;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,0}) << endl; // 3
    cout << sol({3,4,-1,1}) << endl; // 2
    cout << sol({7,8,9,11,12}) << endl; // 1
    cout << sol({1,4,2,-1,6,5}) << endl; // 3
    cout << sol({1}) << endl; // 2
}
