#include "../../template.hpp"

void rec(vector<vector<string>>& res, vector<string>& current, vvb& changes, const string& s, const int n, const int count) {
    if (n == 0 and count == 1) {
        vector<string> temp = current;
        reverse(temp.begin(), temp.end());
        res.push_back(temp);
        return;
    }
    if (n == 0 and count != 1) {
        return;
    }
    if (changes[n][n + count - 1]) {
        current.push_back(s.substr(n - 1, count));
        rec(res, current, changes, s, n - 1, 1);
        current.pop_back();
        rec(res, current, changes, s, n - 1, count + 1);
    }
    else {
        rec(res, current, changes, s, n - 1, count + 1);
    }
}

vector<vector<string>> tab(const string& s) {
    int n = s.size();
    vvb changes(n + 2, vb(n + 1, false));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) changes[i][j] = 0;
            else if (i == j) changes[i][j] = 1;
            else if (j - i == 1) changes[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) changes[i][j] = changes[i + 1][j - 1];
            else changes[i][j] = 0;
        }
    }
    vector<vector<string>> res;
    vector<string> current;
    rec(res, current, changes, s, s.size(), 1);
    return res;
}


int main() { TimeMeasure _; __x();
    cout << tab("aab") << endl; // [["a","a","b"],["aa","b"]]
}
