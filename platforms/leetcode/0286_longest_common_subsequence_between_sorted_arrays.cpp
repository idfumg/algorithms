#include "../../template.hpp"

vi sol(vvi elemsList) {
    int n = elemsList.size();
    array<array<int, 101>, 101> numbers{};
    for (int i = 0; i < n; ++i) {
        for (int elem : elemsList[i]) {
            ++numbers[i][elem];
        }
    }
    vi ans;
    for (int i = 0; i < 101; ++i) {
        int minimum = 1e9;
        for (int j = 0; j < n; ++j) {
            minimum = min(minimum, numbers[j][i]);
        }
        while (minimum-- > 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

vi sol2(vvi elemsList) {
    array<int, 101> count{};
    vi ans;
    for (const auto& elems : elemsList) {
        for (const int value : elems) {
            if (++count[value] == elemsList.size()) {
                ans.push_back(value);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({{1,3,4},{1,4,7,9}}) << endl; // [1,4]
    cout << sol({{2,3,6,8},
                 {1,2,3,5,6,7,10},
                 {2,3,4,6,9}}) << endl; // [2,3,6]
    cout << sol({{1,2,3,4,5},
                 {6,7,8}}) << endl; // []
    cout << sol({{1,2,3,4,5,6,7,9,10},
                 {1,3,4,5,7,8,9,10},
                 {1,2,6,7,8,10},
                 {1,2,3,4,5,6,7,8,9,10},
                 {2,4,5,6,7,8,9,10},
                 {2,6,7,8,9}}) << endl; // [7]
    cout << endl;
    cout << sol2({{1,3,4},{1,4,7,9}}) << endl; // [1,4]
    cout << sol2({{2,3,6,8},
                 {1,2,3,5,6,7,10},
                 {2,3,4,6,9}}) << endl; // [2,3,6]
    cout << sol2({{1,2,3,4,5},
                 {6,7,8}}) << endl; // []
    cout << sol2({{1,2,3,4,5,6,7,9,10},
                 {1,3,4,5,7,8,9,10},
                 {1,2,6,7,8,10},
                 {1,2,3,4,5,6,7,8,9,10},
                 {2,4,5,6,7,8,9,10},
                 {2,6,7,8,9}}) << endl; // [7]
}
