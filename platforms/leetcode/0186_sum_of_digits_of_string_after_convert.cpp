#include "../../template.hpp"

int sol(const string& s, const int K) {
    string arr;
    for (int i = 0; i < s.size(); ++i) {
        arr += to_string(s[i] - 'a' + 1);
    }
    int ans = 0;
    for (int k = 0; k < K; ++k) {
        int temp = 0;
        for (int i = 0; i < arr.size(); ++i) {
            temp += arr[i] - '0';
        }
        arr = to_string(temp);
    }
    return stoi(arr);
}

int main() { TimeMeasure _; __x();
    cout << sol("iiii", 1) << endl; // 36
    cout << sol("leetcode", 2) << endl; // 6
    cout << sol("zbax", 2) << endl; // 8
}
