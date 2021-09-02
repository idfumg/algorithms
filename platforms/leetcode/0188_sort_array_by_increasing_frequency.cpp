#include "../../template.hpp"

vi sol(vi arr) {
    unordered_map<int, int> freq;
    for (const int value : arr) {
        ++freq[value];
    }
    sort(arr.begin(), arr.end(), [&](const int i, const int j){
        if (freq[i] == freq[j]) return i > j;
        return freq[i] < freq[j];
    });
    return arr;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,1,2,2,2,3}) << endl; // 3,1,1,2,2,2
    cout << sol({2,3,1,3,2}) << endl; // 1,3,3,2,2
    cout << sol({-1,1,-6,4,5,-6,1,4,1}) << endl; // 5,-1,4,4,-6,-6,1,1,1
}
