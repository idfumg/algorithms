#include "../../template.hpp"

struct WordDictionary {
    static constexpr int SIZE = 27;
    using Characters = array<int, SIZE>;
    vector<Characters> kids = vector<Characters>(1, Characters{});

    void addWord(const string& s) {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) {
                kids.push_back(Characters{});
                kids[node][idx] = kids.size() - 1;
            }
            node = kids[node][idx];
        }
        kids[node][SIZE - 1] = 1;
    }

    bool search(const string& s, int pos, int node) {
        if (pos == s.size()) return kids[node][SIZE - 1] == 1;

        if (s[pos] == '.') {
            for (int j = 0; j < SIZE - 1; ++j) {
                if (kids[node][j] != 0 and search(s, pos + 1, kids[node][j])) {
                    return true;
                }
            }
            return false;
        }

        if (kids[node][s[pos] - 'a'] == 0) return false;
        return search(s, pos + 1, kids[node][s[pos] - 'a']);
    }

    bool search(const string& s) {
        return search(s, 0, 0);
    }
};

int main() { TimeMeasure _; //__x();
    WordDictionary trie;
    trie.addWord("apple");
    cout << trie.search("apple") << endl; // 1
    cout << trie.search("app") << endl; // 0
    trie.addWord("app");
    cout << trie.search("app") << endl; // 1
    cout << trie.search("a..") << endl; // 1
    cout << trie.search("b..") << endl; // 0
}
