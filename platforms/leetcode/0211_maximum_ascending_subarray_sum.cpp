#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    int current = arr[0];
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            current += arr[i];
        }
        else {
            current = arr[i];
        }
        ans = max(ans, current);
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({10,20,30,5,10,50}) << endl; // 65
    cout << sol({10,20,30,40,50}) << endl; // 150
    cout << sol({12,17,15,13,10,11,12}) << endl; // 33
    cout << sol({100,10,1}) << endl; // 100
}
