#include "../../template.hpp"

int sol(const string& pattern, const string& s) {
    vector<string> words;
    istringstream is(s);
    string word;
    while (is >> word) {
        words.push_back(word);
    }

    if (pattern.size() != words.size()) return 0;

    const int n = pattern.size();
    unordered_map<string, char> m;
    unordered_set<char> ussigned;
    for (int i = 0; i < n; ++i) {
        if (not m.count(words[i])) {
            if (ussigned.count(pattern[i])) {
                return 0;
            }
            m[words[i]] = pattern[i];
            ussigned.insert(pattern[i]);
        }
        else {
            if (m[words[i]] != pattern[i]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() { TimeMeasure _; __x();
    cout << sol("abba", "dog cat cat dog") << endl; // 1
    cout << sol("abba", "dog cat cat fish") << endl; // 0
    cout << sol("aaaa", "dog cat cat dog") << endl; // 0
    cout << sol("abba", "dog dog dog dog") << endl; // 0
}
