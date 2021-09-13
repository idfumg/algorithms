#include "../../template.hpp"

int sol(const string& pattern, const string& s) {
    const int n = s.size();
    string word;
    int idx = 0;
    unordered_map<string, char> dict;
    array<int, 26> used{};
    for (int i = 0; i <= n; ++i) {
        if (i < n and s[i] != ' ') {
            word += s[i];
            continue;
        }

        if (dict.count(word) and pattern[idx] != dict[word]) return false;
        if (not dict.count(word) and used[pattern[idx] - 'a']) return false;

        used[pattern[idx] - 'a'] = 1;
        dict.insert({word, pattern[idx++]});
        word.clear();
    }
    return idx == pattern.size();
}

int main() { TimeMeasure _; __x();
    cout << sol("abba", "dog cat cat dog") << endl; // 1
    cout << sol("abba", "dog cat cat fish") << endl; // 0
    cout << sol("aaaa", "dog cat cat dog") << endl; // 0
    cout << sol("abba", "dog dog dog dog") << endl; // 0
    cout << sol("jquery", "jquery") << endl; // 0
}
