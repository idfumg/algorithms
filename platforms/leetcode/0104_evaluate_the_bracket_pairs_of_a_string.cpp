#include "../../template.hpp"

string tab(const string& s, const unordered_map<string, string>& p) {
    const int n = s.size();
    string temp;
    bool fill_temp = false;
    string ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            fill_temp = true;
            continue;
        }
        else if (s[i] == ')') {
            fill_temp = false;
            if (p.count(temp)) {
                ans += p.at(temp);
            }
            else {
                ans += "?";
            }
            temp.clear();
            continue;
        }
        if (fill_temp) {
            temp += s[i];
        }
        else {
            ans += s[i];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("(name)is(age)yearsold", {{"name","bob"},{"age","two"}}) << endl; // bobistwoyearsold
    cout << tab("hi(name)", {{"a","b"}}) << endl; // hi?
    cout << tab("(a)(a)(a)aaa", {{"a","yes"}}) << endl; // yesyesyesaaa
    cout << tab("(a)(b)", {{"a","b"},{"b","a"}}) << endl; // ba
}
