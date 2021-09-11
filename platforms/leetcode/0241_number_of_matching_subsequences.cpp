#include "../../template.hpp"

bool is_lcs(const string& s, const string& t, const vi& count) {
    int m = s.size();
    int n = t.size();
    int i = 0;
    int j = 0;
    while (i < m and j < n) {
        int c = count[j];
        if (s[i] == t[j]) {
            ++i;
            if (--c == 0) ++j;
        }
        else {
            ++j;
        }
    }
    return i == m;
}

int sol(const string& s_, const vs& words) {
    int ans = 0;
    string s;
    vi count;
    for (const char ch : s_) {
        if (count.empty()) {
            count.push_back(1);
            s += ch;
        }
        else if (ch == s.back()) {
            ++count.back();
        }
        else {
            count.push_back(1);
            s += ch;
        }
    }
    for (const string& word : words) {
        if (is_lcs(word, s, count)) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("abcde", {"a","bb","acd","ace"}) << endl; // 3
    cout << sol("dsahjpjauf", {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}) << endl; // 2
    cout << sol("btovxbkumc", {"btovxbku","to","zueoxxxjme","yjkclbkbtl"}) << endl; // 2
    cout << sol("rwpddkvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvjubjgloeofnpjqlkdsqvruvabjrikfwronbrdyyjnakstqjac", {"wpddkvbnn","lnagtva","kvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvju","rwpddkvbnnugln","gloeofnpjqlkdsqvruvabjrikfwronbrdyyj","vbgeinupkvgmgxeaaiuiyojmoqkahwvbpwugdainxciedbdkos","mspuhbykmmumtveoighlcgpcapzczomshiblnvhjzqjlfkpina","rgmliajkiknongrofpugfgajedxicdhxinzjakwnifvxwlokip","fhepktaipapyrbylskxddypwmuuxyoivcewzrdwwlrlhqwzikq","qatithxifaaiwyszlkgoljzkkweqkjjzvymedvclfxwcezqebx"}) << endl; // 5
}
