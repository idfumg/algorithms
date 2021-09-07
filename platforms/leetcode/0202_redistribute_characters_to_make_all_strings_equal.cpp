#include "../../template.hpp"

int sol(const vector<string>& arr) {
    array<int, 32> chars{};
    if (arr.size() <= 1) return 1;
    for (const string& value : arr) {
        for (const char ch : value) {
            ++chars[ch - 'a'];
        }
    }
    const int n = arr.size();
    for (int i = 0; i < chars.size(); ++i) {
        if (chars[i] > 0 and chars[i] % n != 0) {
            return 0;
        }
    }
    return 1;
}

int main() { TimeMeasure _; //__x();
    cout << sol({"abc","aabc","bc"}) << endl; // 1
    cout << sol({"ab","a"}) << endl; // 0
    cout << sol({"az","a"}) << endl; // 0
    cout << sol({"abbab"}) << endl; // 1
    cout << sol({"caaaaa","aaaaaaaaa","a","bbb","bbbbbbbbb","bbb","cc","cccccccccccc","ccccccc","ccccccc","cc","cccc","c","cccccccc","c"}) << endl; // 1
}
