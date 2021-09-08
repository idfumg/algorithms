#include "../../template.hpp"

string sol_(const string& s, const int n, const int c) {
    if (n == 0) return string(1, c + '0') + s[n];
    if (s[n] == s[n - 1]) return sol_(s, n - 1, c + 1);
    return sol_(s, n - 1, 1) + string(1, c + '0') + s[n];
}

string sol(const int n) {
    if (n == 1) return "1";
    const string s = sol(n - 1);
    return sol_(s, s.size() - 1, 1);
}

string sol2(const int num) {
    if (num == 1) return "1";
    const string s = sol2(num - 1);
    string ans;
    int count = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1] ) {
            ++count;
        }
        else {
            ans += string(1, count + '0') + s[i - 1];
            count = 1;
        }
    }
    ans += string(1, count + '0') + s.back();
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol(1) << endl; // 1
    cout << sol(2) << endl; // 11
    cout << sol(3) << endl; // 21
    cout << sol(4) << endl; // 1211
    cout << endl;
    cout << sol2(1) << endl; // 1
    cout << sol2(2) << endl; // 11
    cout << sol2(3) << endl; // 21
    cout << sol2(4) << endl; // 1211
}
