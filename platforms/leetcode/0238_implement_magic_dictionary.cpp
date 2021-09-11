#include "../../template.hpp"

struct TrieNode {
    array<unique_ptr<TrieNode>, 27> kids;
    bool is_terminal() const { return kids.back().get(); }
    bool is_valid(char ch) const { return kids[ch - 'a'].get(); }
    TrieNode* next(char ch) const { return kids[ch - 'a'].get(); }
};

struct MagicDictionary {
    unique_ptr<TrieNode> root = make_unique<TrieNode>();
    void addWord(string word) {
        TrieNode* node = root.get();
        for (char ch : word) {
            if (not node->kids[ch - 'a']) node->kids[ch - 'a'] = make_unique<TrieNode>();
            node = node->kids[ch - 'a'].get();
        }
        node->kids.back() = make_unique<TrieNode>();
    }
    bool search(string word, int n, int k, TrieNode* root) {
        if (k < 0 or not root) return 0;
        if (n > word.size()) return root->is_terminal() and k == 0;
        if (root->is_valid(word[n - 1]) and search(word, n + 1, k, root->next(word[n - 1]))) return 1;
        for (int i = 0; k > 0 and i < root->kids.size(); ++i) {
            if (i != word[n - 1] - 'a' and search(word, n + 1, k - 1, root->kids[i].get())) {
                return 1;
            }
        }
        return 0;
    }
    bool search(string word) {
        return search(word, 1, 1, root.get());
    }
};

int main() { TimeMeasure _; __x();
    {
        MagicDictionary trie;
        trie.addWord("hello");
        trie.addWord("hallo");
        cout << trie.search("hello") << endl; // 1
        cout << trie.search("hhllo") << endl; // 1
        cout << trie.search("hell") << endl; // 0
        cout << trie.search("leetcoded") << endl; // 0
    }
    cout << endl;
    {
        MagicDictionary trie;
        trie.addWord("hello");
        cout << trie.search("hello") << endl; // 0
        cout << trie.search("hhllo") << endl; // 1
        cout << trie.search("hell") << endl; // 0
        cout << trie.search("leetcoded") << endl; // 0
    }
}
