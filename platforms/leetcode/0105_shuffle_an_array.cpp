#include "../../template.hpp"

vi tab(const vi& arr) {
    const int n = arr.size();
    vi ans = arr;
    for (int i = n - 1; i >= 1; --i) {
        const int idx = rand() % (i + 1);
        swap(ans[idx], ans[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4,5}) << endl;
}
