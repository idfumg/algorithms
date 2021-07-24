#include "../../template.hpp"

void rec(const string& s, const unordered_set<string>& words, const int n, const int count, vector<string>& res, vector<string>& current) {
    if (n == 0 and count == 1) {
        vector<string> current_temp = current;
        reverse(current_temp.begin(), current_temp.end());
        string temp;
        for (const string& word : current_temp) {
            temp += word;
            temp += ' ';
        }
        temp.pop_back();
        res.push_back(temp);
        return;
    }
    if (n == 0 and count != 1) {
        return;
    }
    const auto word = s.substr(n - 1, count);
    if (words.count(word)) {
        current.push_back(word);
        rec(s, words, n - 1, 1, res, current);
        current.pop_back();
    }
    rec(s, words, n - 1, count + 1, res, current);
}

vector<string> rec(const string& s, const unordered_set<string>& words) {
    vector<string> res;
    vector<string> current;
    rec(s, words, s.size(), 1, res, current);
    return res;
}

int main() { TimeMeasure _; __x();
    cout << rec("catsanddog", {"cat","cats","and","sand","dog"}) << endl;
    cout << rec("pineapplepenapple", {"apple","pen","applepen","pine","pineapple"}) << endl;
cout << rec("catsandog", {"cats","dog","sand","and","cat"}) << endl;
}
