#include "../../template.hpp"

vi tab(const vi& queries, const int m) {
    vi arr(m);
    iota(arr.begin(), arr.end(), 1);
    vi ans;
    for (const int query : queries) {
        int i = 0;
        for (; i < m; ++i) {
            if (query == arr[i]) {
                ans.push_back(i);
                break;
            }
        }
        arr.erase(arr.begin() + i);
        arr.insert(arr.begin(), query);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({3,1,2,1}, 5) << endl; // 2,1,2,1
}
