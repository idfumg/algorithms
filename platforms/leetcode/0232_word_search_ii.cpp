#include "../../template.hpp"

const vvc board = {{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'}};
const vs words = {"lllllll","fffffff","ssss","s","rr","xxxx","ttt","eee","ppppppp","iiiiiiiii","xxxxxxxxxx","pppppp","xxxxxx","yy","jj","ccc","zzz","ffffffff","r","mmmmmmmmm","tttttttt","mm","ttttt","qqqqqqqqqq","z","aaaaaaaa","nnnnnnnnn","v","g","ddddddd","eeeeeeeee","aaaaaaa","ee","n","kkkkkkkkk","ff","qq","vvvvv","kkkk","e","nnn","ooo","kkkkk","o","ooooooo","jjj","lll","ssssssss","mmmm","qqqqq","gggggg","rrrrrrrrrr","iiii","bbbbbbbbb","aaaaaa","hhhh","qqq","zzzzzzzzz","xxxxxxxxx","ww","iiiiiii","pp","vvvvvvvvvv","eeeee","nnnnnnn","nnnnnn","nn","nnnnnnnn","wwwwwwww","vvvvvvvv","fffffffff","aaa","p","ddd","ppppppppp","fffff","aaaaaaaaa","oooooooo","jjjj","xxx","zz","hhhhh","uuuuu","f","ddddddddd","zzzzzz","cccccc","kkkkkk","bbbbbbbb","hhhhhhhhhh","uuuuuuu","cccccccccc","jjjjj","gg","ppp","ccccccccc","rrrrrr","c","cccccccc","yyyyy","uuuu","jjjjjjjj","bb","hhh","l","u","yyyyyy","vvv","mmm","ffffff","eeeeeee","qqqqqqq","zzzzzzzzzz","ggg","zzzzzzz","dddddddddd","jjjjjjj","bbbbb","ttttttt","dddddddd","wwwwwww","vvvvvv","iii","ttttttttt","ggggggg","xx","oooooo","cc","rrrr","qqqq","sssssss","oooo","lllllllll","ii","tttttttttt","uuuuuu","kkkkkkkk","wwwwwwwwww","pppppppppp","uuuuuuuu","yyyyyyy","cccc","ggggg","ddddd","llllllllll","tttt","pppppppp","rrrrrrr","nnnn","x","yyy","iiiiiiiiii","iiiiii","llll","nnnnnnnnnn","aaaaaaaaaa","eeeeeeeeee","m","uuu","rrrrrrrr","h","b","vvvvvvv","ll","vv","mmmmmmm","zzzzz","uu","ccccccc","xxxxxxx","ss","eeeeeeee","llllllll","eeee","y","ppppp","qqqqqq","mmmmmm","gggg","yyyyyyyyy","jjjjjj","rrrrr","a","bbbb","ssssss","sss","ooooo","ffffffffff","kkk","xxxxxxxx","wwwwwwwww","w","iiiiiiii","ffff","dddddd","bbbbbb","uuuuuuuuu","kkkkkkk","gggggggggg","qqqqqqqq","vvvvvvvvv","bbbbbbbbbb","nnnnn","tt","wwww","iiiii","hhhhhhh","zzzzzzzz","ssssssssss","j","fff","bbbbbbb","aaaa","mmmmmmmmmm","jjjjjjjjjj","sssss","yyyyyyyy","hh","q","rrrrrrrrr","mmmmmmmm","wwwww","www","rrr","lllll","uuuuuuuuuu","oo","jjjjjjjjj","dddd","pppp","hhhhhhhhh","kk","gggggggg","xxxxx","vvvv","d","qqqqqqqqq","dd","ggggggggg","t","yyyy","bbb","yyyyyyyyyy","tttttt","ccccc","aa","eeeeee","llllll","kkkkkkkkkk","sssssssss","i","hhhhhh","oooooooooo","wwwwww","ooooooooo","zzzz","k","hhhhhhhh","aaaaa","mmmmm"};

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

static const int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vvc& board, TrieNode* root, vector<string>& ans, string& word, const vi& at) {
    const int m = board.size();
    const int n = board[0].size();

    if (root->is_terminal()) {
        ans.push_back(word);
        root->kids.back().reset();
    }

    const char ch = board[at[0]][at[1]];
    board[at[0]][at[1]] = -1;
    for (const auto& direction : directions) {
        const int i = at[0] + direction[0];
        const int j = at[1] + direction[1];
        if (i >= 0 and j >= 0 and i < m and j < n and board[i][j] != -1 and root->is_valid(board[i][j])) {
            word += board[i][j];
            dfs(board, root->next(board[i][j]), ans, word, {i, j});
            word.pop_back();
        }
    }
    board[at[0]][at[1]] = ch;
}

vs sol(vvc& board, TrieNode* root, const int total) {
    const int m = board.size();
    const int n = board[0].size();
    vector<string> ans;
    string word;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (root->is_valid(board[i][j]) and ans.size() < total) {
                word += board[i][j];
                dfs(board, root->next(board[i][j]), ans, word, {i, j});
                word.pop_back();
            }
        }
    }
    return ans;
}

vs sol(vvc board, const vs& words) {
    Trie trie;
    for (const auto& word : words) {
        trie.insert(word);
    }
    return sol(board, trie.root.get(), words.size());
}

int main() { TimeMeasure _; __x();
    cout << sol({{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},
                {"oath","pea","eat","rain"}) << endl; // ["eat","oath"]
    cout << sol({{'a','b'},{'c','d'}},
                {"abcb"}) << endl; // []
    cout << sol({{'a'}},
                {"a"}) << endl; // ["a"]
    cout << sol({{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'}},
                {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}) << endl; // ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    cout << sol({{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},
                {"oath","pea","eat","rain","hklf", "hf"}) << endl; // ["oath","eat","hklf","hf"]
    cout << sol(board, words) << endl; //
}
