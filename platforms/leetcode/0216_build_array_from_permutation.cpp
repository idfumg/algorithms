#include "../../template.hpp"

vi sol(const vi& arr) {
    const int n = arr.size();
    vi ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = arr[arr[i]];
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({0,2,1,5,3,4}) << endl; // 0,1,2,4,5,3
    cout << sol({5,0,1,2,3,4}) << endl; // 4,5,0,1,2,3
}
