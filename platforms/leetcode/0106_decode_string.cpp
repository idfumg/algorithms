#include "../../template.hpp"

string multiply_string(const int n, const string& s) {
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += s;
    }
    return ans;
}

int read_number(const string& s, int& idx) {
    int ans = 0;
    for (; idx < s.size() and isdigit(s[idx]); ++idx) {
        ans = ans * 10 + s[idx] - '0';
    }
    return ans;
}

string read_string(const string& s, int& idx) {
    string ans;
    for (; idx < s.size() and not isdigit(s[idx]) and s[idx] != ']'; ++idx) {
        ans += s[idx];
    }
    return ans;
}

string rec(const string& s, int& idx) {
    if (idx >= s.size()) return "";
    if (isdigit(s[idx])) {
        const int number = read_number(s, idx);
        ++idx; // [
        const string a = multiply_string(number, rec(s, idx));
        ++idx; // ]
        return a + rec(s, idx);
    }
    else {
        const string temp = read_string(s, idx);
        return isdigit(s[idx]) ? (temp + rec(s, idx)) : temp;
    }
}

string rec(const string& s) {
    int idx = 0;
    return rec(s, idx);
}

int main() { TimeMeasure _; __x();
    cout << rec("3[a]2[bc]") << endl; // aaabcbc
    cout << rec("3[a2[c]]") << endl; // accaccacc
    cout << rec("2[abc]3[cd]ef") << endl; // abcabccdcdcdef
    cout << rec("abc3[cd]xyz") << endl; // abccdcdcdxyz
}
