#include "../../template.hpp"

vi tab(vi nums) {
    sort(nums.begin(), nums.end());
    return nums;
}

int main() { TimeMeasure _; __x();
    cout << tab({5,2,3,1}) << endl; // 1,2,3,5
    cout << tab({5,1,1,2,0,0}) << endl; // 0,0,1,1,2,5
}
