#include "../../template.hpp"

int sol(const vi& arr, const int k) {
    const int n = arr.size();
    multiset<int> pq;
    for (int i = 0; i < n; ++i) {
        pq.insert(arr[i]);
        if (pq.size() > k) pq.erase(pq.begin());
    }
    return *pq.cbegin();
}

int main() { TimeMeasure _; __x();
    cout << sol({3,2,1,5,6,4}, 2) << endl; // 5
    cout << sol({3,2,3,1,2,4,5,5,6}, 4) << endl; // 4
}
