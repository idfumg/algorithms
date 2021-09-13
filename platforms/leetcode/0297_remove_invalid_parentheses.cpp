#include "../../template.hpp"

bool is_valid(string s) {
    int left = 0;
    for (char ch : s) {
        if (ch == '(') ++left;
        else if (ch == ')' and left == 0) return 0;
        else if (ch == ')') --left;
    }
    return left == 0;
}

vs brute(string s) {
    unordered_set<string> ans;
    int n = s.size();
    int total_letters = count_if(s.begin(), s.end(), [](char ch){return isalpha(ch);});
    for (int i = 0; i < (1 << n); ++i) {
        string temp;
        int letters = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                temp += s[j];
                if (isalpha(s[j])) ++letters;
            }
        }
        if (is_valid(temp) and letters == total_letters) {
            if (not ans.empty() and temp.size() > ans.begin()->size()) {
                ans.clear();
            }
            ans.insert(temp);
        }
    }
    return vs(ans.begin(), ans.end());
}

void sol(const string& s, unordered_map<int, int>& ans, int mask, int i, int count, int right) {
    if (right < 0) {
        return;
    }
    if (i < 0 and right != 0) {
        return;
    }
    if (i < 0 and right == 0) {
        if (not ans.empty() and ans.begin()->second < count) ans.clear();
        if (ans.empty() or ans.begin()->second == count) ans.insert({mask, count});
        return;
    }
    if (s[i] == '(' or s[i] == ')') {
        sol(s, ans, mask, i - 1, count, right);
    }
    if (s[i] == ')') ++right;
    else if (s[i] == '(') --right;
    sol(s, ans, mask | (1 << i), i - 1, count + 1, right);
}

vs sol(const string& s) {
    unordered_map<int, int> ans;
    int n = s.size();
    sol(s, ans, 0, s.size() - 1, 0, 0);

    unordered_set<string> uniq;
    for (auto& [mask, count] : ans) {
        string temp(count, ' ');
        int idx = count - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (mask & (1 << i)) {
                temp[idx--] = s[i];
            }
        }
        uniq.insert(temp);
    }
    return vs(uniq.begin(), uniq.end());
}

int main() { TimeMeasure _; __x();
    cout << brute("()())()") << endl; // ["(())()","()()()"]
    cout << brute("(a)())()") << endl; // ["(a())()","(a)()()"]
    cout << brute(")(") << endl; // [""]
    cout << "aaaaa" << endl; //cout << brute("((((((((((((((((((((aaaaa") << endl; // [aaaaa]
    cout << endl;
    cout << sol("()())()") << endl; // ["(())()","()()()"]
    cout << sol("(a)())()") << endl; // ["(a())()","(a)()()"]
    cout << sol(")(") << endl; // [""]
    cout << sol("((((((((((((((((((((aaaaa") << endl; // [aaaaa]
}
