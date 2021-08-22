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

    bool search(const string& s) {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) return false;
            node = kids[node][idx];
        }
        return kids[node][26];
    }

    bool starts_with(const string& s) {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) return false;
            node = kids[node][idx];
        }
        return true;
    }
};

int main() { TimeMeasure _; //__x();
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; // 1
    cout << trie.search("app") << endl; // 0
    cout << trie.starts_with("app") << endl; // 1
    cout << trie.starts_with("apr") << endl; // 0
    trie.insert("app");
    cout << trie.search("app") << endl; // 1
}
