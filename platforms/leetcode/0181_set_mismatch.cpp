#include "../../template.hpp"

vi sol(vi arr) {
    array<int, 10001> values{};
    int first = 0;
    for (const int value : arr) {
        if (++values[value] == 2) {
            first = value;
        }
    }
    for (int i = 1; i < values.size(); ++i) {
        if (values[i] == 0) {
            return {first, i};
        }
    }
    return {};
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,2,4}) << endl; // 2,3
    cout << sol({1,1}) << endl; // 1,2
    cout << sol({2,2}) << endl; // 2,1
}
