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

    bool search(const string& s) const {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) return false;
            node = kids[node][idx];
        }
        return kids[node][26];
    }

    bool starts_with(const string& s) const {
        int node = 0;
        for (const char ch : s) {
            const int idx = ch - 'a';
            if (kids[node][idx] == 0) return false;
            node = kids[node][idx];
        }
        return true;
    }
};

bool is_all_prefixes_exists(const string& word, const Trie& trie) {
    const int n = word.size();
    for (int i = n - 2; i >= 0; --i) {
        if (i + 1 < n and not trie.search(word.substr(0, i + 1))) {
            return false;
        }
    }
    return true;
}

string sol(const vs& words) {
    Trie trie;
    for (const auto& word : words) {
        trie.insert(word);
    }
    set<string> ans;
    for (const auto& word : words) {
        if (is_all_prefixes_exists(word, trie)) {
            ans.insert(word);
        }
    }
    if (ans.empty()) return "";
    string temp;
    for (const string& s : ans) {
        if (s.size() > temp.size()) {
            temp = s;
        }
        else if (s.size() == temp.size() and temp > s) {
            temp = s;
        }
    }
    return temp;
}

int main() { TimeMeasure _; //__x();
    cout << sol({"w","wo","wor","worl","world"}) << endl; // world
    cout << sol({"a","banana","app","appl","ap","apply","apple"}) << endl; // apple
    cout << sol({"b","br","bre","brea","break","breakf","breakfa","breakfas","breakfast","l","lu","lun","lunc","lunch","d","di","din","dinn","dinne","dinner"}) << endl; // breakfast
}
