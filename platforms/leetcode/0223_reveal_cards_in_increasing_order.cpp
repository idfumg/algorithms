#include "../../template.hpp"

vi sol(vi nums) {
    sort(nums.rbegin(), nums.rend());
    deque<int> d = {nums[0]};
    for (int i = 1; i < nums.size(); ++i) {
        d.push_front(d.back());
        d.pop_back();
        d.push_front(nums[i]);
    }
    return vi(d.begin(), d.end());
}

int main() { TimeMeasure _; __x();
    cout << sol({17,13,11,2,3,5,7}) << endl; // 2,13,3,11,5,17,7
}
