#include "../../template.hpp"

vi sol(const vi& arr) {
    vi ans = arr;
    for (const int value : arr) {
        ans.push_back(value);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,1}) << endl; // 1,2,1,1,2,1
    cout << sol({1,3,2,1}) << endl; // 1,3,2,1,1,3,2,1
}
