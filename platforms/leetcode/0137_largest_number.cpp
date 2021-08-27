#include "../../template.hpp"

string sol(vi arr) {
    sort(arr.begin(), arr.end(), [](const int a, const int b) {
        const string as = to_string(a);
        const string bs = to_string(b);
        return as + bs > bs + as;
    });
    string ans;
    for (int i = 0; i < arr.size(); ++i) {
        if (ans.empty() and arr[i] == 0) continue;
        ans += to_string(arr[i]);
    }
    return ans.empty() ? "0" : ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({10,2}) << endl; // 210
    cout << sol({3,30,34,5,9}) << endl; // 9534330
    cout << sol({1}) << endl; // 1
    cout << sol({10}) << endl; // 10
    cout << sol({0, 0}) << endl; // 0
}
