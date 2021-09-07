#include "../../template.hpp"

int sol(const vector<string>& arr, const string& p) {
    int ans = 0;
    for (const string& s : arr) {
        if (p.find(s) != string::npos) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({"a","abc","bc","d"}, "abc") << endl; // 3
    cout << sol({"a","b","c"}, "aaaaabbbbb") << endl; // 2
    cout << sol({"a","a","a"}, "ab") << endl; // 3
}
