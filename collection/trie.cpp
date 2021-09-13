#include "../template.hpp"

struct TrieNode {
    static constexpr uint8_t SIZE = 32;
    array<unique_ptr<TrieNode>, SIZE> kids;

    bool is_terminal() const noexcept { return kids.back().get(); }
    bool is_valid(const char ch) const noexcept { return kids[ch - 'a'].get(); }
    TrieNode* next(const char ch) const noexcept { return kids[ch - 'a'].get(); }
};

struct Trie {
    unique_ptr<TrieNode> root = make_unique<TrieNode>();

    void insert(const string& word) noexcept {
        TrieNode* node = root.get();
        for (const char ch : word) {
            if (not node->kids[ch - 'a']) {
                node->kids[ch - 'a'] = make_unique<TrieNode>();
            }
            node = node->kids[ch - 'a'].get();
        }
        node->kids.back() = make_unique<TrieNode>();
    }

    bool exists(const string& word) const noexcept {
        TrieNode* node = root.get();
        for (const char ch : word) {
            if (not node->kids[ch - 'a']) return 0;
            node = node->kids[ch - 'a'].get();
        }
        return node->is_terminal();
    }

    bool starts(const string& word) const noexcept {
        TrieNode* node = root.get();
        for (const char ch : word) {
            if (not node->kids[ch - 'a']) return 0;
            node = node->kids[ch - 'a'].get();
        }
        return 1;
    }
};

int main() { TimeMeasure _; //__x();
    Trie trie;
    trie.insert("apple");
    cout << trie.exists("apple") << endl; // 1
    cout << trie.exists("app") << endl; // 0
    cout << trie.starts("app") << endl; // 1
    cout << trie.starts("apr") << endl; // 0
    trie.insert("app");
    cout << trie.exists("app") << endl; // 1
}
