#include "../../template.hpp"

int tab(const vi& a, const vi& b) {
    const int n = a.size();
    vi idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&a, &b](const int i, const int j){
        return a[i] + b[i] > a[j] + b[j];
    });
    int first = 0;
    int second = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) second += b[idx[i]];
        else first += a[idx[i]];
    }
    if (first == second) return 0;
    if (first > second) return 1;
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,3}, {2,1}) << endl; // 1
    cout << tab({1,2}, {3,1}) << endl; // 0
    cout << tab({2,4,3}, {1,6,7}) << endl; // -1
}
