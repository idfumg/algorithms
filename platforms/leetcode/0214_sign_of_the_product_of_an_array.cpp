#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) ans *= -1;
        else if (arr[i] == 0) return 0;
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({-1,-2,-3,-4,3,2,1}) << endl; // 1
    cout << sol({1,5,0,2,-3}) << endl; // 0
    cout << sol({-1,1,-1,1,-1}) << endl; // -1
}
