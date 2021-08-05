#include "../../template.hpp"

bool tab(const string& s, const int k) {
    int n = s.size();
    vvb changes(n + 2, vb(n + 1, false));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) changes[i][j] = 0;
            else if (i == j) changes[i][j] = 1;
            else if (j - i == 1) changes[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) changes[i][j] = changes[i + 1][j - 1];
            else changes[i][j] = 0;
        }
    }
    vvvb dp(k + 1, vvb(n + 1, vb(n + 2, false)));
    for (int i = n; i >= 3; --i) {
        if (changes[i][n]) {
            for (int j = i - 1; j >= 2; --j) {
                if (changes[1][j - 1] and changes[j][i - 1]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() { TimeMeasure _; __x();
    cout << tab("aaa", 3) << endl; // 1
    cout << tab("abc", 3) << endl; // 1
    cout << tab("aabbc", 3) << endl; // 1
    cout << tab("leetcode", 3) << endl; // 0
    cout << tab("abcbdd", 3) << endl; // 1
    cout << tab("bcbddxy", 3) << endl; // 0
    cout << tab("segqdxmrtmwsugwzpsyjazltbmqdatggqknnuanoytezsysexnfnhgvayoqaovignvsxwhxxummpbmmiqnwqfqwnqimmbpmmuxxhwxsvngivoaqoyavghnfnxesyszetyonaunnkqggtadqmbtlzajyspzwguswmtrmxdqgesunydfwknxujfqzslwngpnjovjxjoughmntupqwpwnonkbtxneevcarwaytegymsafxgroedvdyhroaxsaybyolefwvwseltqsbathukdieawjyycregtovfliuhazaonkavwoibedabhhbadebiowvaknoazahuilfvotgercyyjwaeidkuhtabsqtleswvwfeloybyasxaorhydvdeorgxfasmygetyawracveenxtbknonwpwqputnmhguojxjvojnpgnwlszqfjuxnkwfdynukkhuarxrxdfywseybytyjrlmsksufcxirabcbnuwzhcoxdvqtamxbhiqectnkibdauafffakqkxnvtyvxrfaqqejptkgbsfdffmneolukfzensnqquklmrandyllbiyilallbdnwdbwhvurzudmbjcyopuyjxxnoqzxzsiptpcxdeyigfhgciaddaicghfgiyedxcptpiszxzqonxxjyupoycjbmduzruvhwbdwndbllaliyibllydnarmlkuqqnsnezfkuloenmffdfsbgktpjeqqafrxvytvnxkqkafffauadbikntceqihbxmatqvdxochzwunbcbarixcfusksmlrjytybyeswyfdxrxrauhkk", 3) << endl; // 1
}
