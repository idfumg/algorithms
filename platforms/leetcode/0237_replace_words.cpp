#include "../../template.hpp"

struct Trie {
    using Characters = array<int, 27>;
    vector<Characters> kids = vector<Characters>(1, Characters{});

    void insert(const string& s) {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) {
                kids.push_back(Characters{});
                kids[node][idx] = kids.size() - 1;
            }
            node = kids[node][idx];
        }
        kids[node][26] = 1;
    }

    string search(const string& s) {
        int node = 0;
        string ans;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][26]) return ans;
            if (kids[node][idx] == 0) return s;
            node = kids[node][idx];
            ans += ch;
        }
        return kids[node][26] ?  ans : s;
    }
};

string sol(const string& s, const vs& words) {
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }
    string ans;
    int count = 0;
    int idx = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            const string temp = s.substr(idx, count);
            const string word = trie.search(temp);
            ans += word;
            if (i != s.size() - 1) ans += ' ';

            idx = -1;
            count = 0;
        }
        else {
            if (idx == -1) idx = i;
            ++count;
        }
    }
    if (count > 0) {
        const string temp = s.substr(idx, count);
        const string word = trie.search(temp);
        ans += word;
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol("the cattle was rattled by the battery", {"cat","bat","rat"}) << endl; // "the cat was rat by the bat"
    cout << sol("aadsfasf absbs bbab cadsfafs", {"a","b","c"}) << endl; // "a a b c"
    cout << sol("a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa", {"a", "aa", "aaa", "aaaa"}) << endl; // "a a a a a a a a bbb baba a"
    cout << sol("the cattle was rattled by the battery", {"catt","cat","bat","rat"}) << endl; // "the cat was rat by the bat"
    cout << sol("it is abnormal that this solution is accepted", {"ac","ab"}) << endl; // "it is ab that this solution is ac"
}
