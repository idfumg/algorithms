#include "../../template.hpp"

void rec(const string& s, unordered_set<string>& ans, int current, const int n, string& temp) {
    if (n < 0) {
        ans.insert(temp);
        return;
    }
    rec(s, ans, current, n - 1, temp);
    if (current & (1 << n)) return;
    current |= (1 << n);
    temp.push_back(s[n]);
    rec(s, ans, current, s.size() - 1, temp);
    temp.pop_back();
    current &= ~(1 << n);
}

int rec(const string& s) {
    unordered_set<string> ans;
    int current = 0;
    string temp;
    rec(s, ans, current, s.size() - 1, temp);
    return ans.size() - 1;
}

int main() { TimeMeasure _; __x();
    cout << rec("AAB") << endl; // 8
    cout << rec("AAABBC") << endl; // 188
    cout << rec("V") << endl; // 1
}
