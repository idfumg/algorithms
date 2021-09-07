#include "../../template.hpp"

double sol(const vi& arr) {
    const int n = arr.size();
    int mini = INF;
    int maxi = -INF;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }
    return (double)(sum - mini - maxi) / (n - 2);
}

int main() { TimeMeasure _; //__x();
    cout << sol({4000,3000,1000,2000}) << endl; // 2500.00000
    cout << sol({1000,2000,3000}) << endl; // 2000.00000
    cout << sol({6000,5000,4000,3000,2000,1000}) << endl; // 3500.00000
    cout << sol({8000,9000,2000,3000,6000,1000}) << endl; // 4750.00000
}
