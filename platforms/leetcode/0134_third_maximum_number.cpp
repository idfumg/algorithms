#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    const int k = 3;
    set<int> pq;
    for (int i = 0; i < n; ++i) {
        pq.insert(arr[i]);
        if (pq.size() > k) pq.erase(pq.begin());
    }
    if (pq.size() < k) return *pq.rbegin();
    return *pq.cbegin();
}

int main() { TimeMeasure _; __x();
    cout << sol({3,2,1}) << endl; // 1
    cout << sol({1,2}) << endl; // 2
    cout << sol({2,2,3,1}) << endl; // 1
    cout << sol({1,1,2}) << endl; // 2
}
