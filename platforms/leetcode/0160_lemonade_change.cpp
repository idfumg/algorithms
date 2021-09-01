#include "../../template.hpp"

int sol(const vi& arr) {
    vi values(3);
    const int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 5) {
            ++values[0];
        }
        else if (arr[i] == 10) {
            if (values[0] > 0) --values[0], ++values[1];
            else return 0;
        }
        else {
            if (values[0] > 0 and values[1] > 0) --values[0], --values[1];
            else if (values[0] >= 3) values[0] -= 3;
            else return 0;
        }
    }
    return 1;
}

int main() { TimeMeasure _; __x();
    cout << sol({5,5,5,10,20}) << endl; // 1
    cout << sol({5,5,10,10,20}) << endl; // 0
    cout << sol({5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5}) << endl; // 1
}
