#include "../../template.hpp"

int sol(const vi& arr) {
    unordered_set<int> m;
    int zeroes = 0;
    for (int i = 0; i < arr.size(); ++i) {
        m.insert(arr[i]);
        if (arr[i] == 0) ++zeroes;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0 and m.count(2 * arr[i])) {
            return 1;
        }
        else if (arr[i] == 0 and zeroes > 1) {
            return 1;
        }
    }
    return 0;
}

int main() { TimeMeasure _; //__x();
    cout << sol({10,2,5,3}) << endl; // 1
    cout << sol({7,1,14,11}) << endl; // 1
    cout << sol({3,1,7,11}) << endl; // 0
    cout << sol({-2,0,10,-19,4,6,-8}) << endl; // 0
}
