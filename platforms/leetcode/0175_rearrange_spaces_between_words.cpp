#include "../../template.hpp"

string sol(const string& s) {
    string word;
    istringstream is(s);
    vector<string> words;
    while (is >> word) {
        words.push_back(word);
    }

    const int total_spaces = count(s.cbegin(), s.cend(), ' ');
    if (words.size() == 1) return words[0] + string(total_spaces, ' ');
    if (word.empty()) return string(total_spaces, ' ');

    const int spaces = total_spaces / (words.size() - 1);
    const int remaining = total_spaces % (words.size() - 1);

    string ans;
    for (int i = 0; i < words.size(); ++i) {
        ans += words[i];
        if (i != words.size() - 1) ans += string(spaces, ' ');
    }
    return ans + string(remaining, ' ');
}

int main() { TimeMeasure _; __x();
    cout << sol("  this   is  a sentence ") << endl; // "this   is   a   sentence"
    cout << sol(" practice   makes   perfect") << endl; // "practice   makes   perfect "
    cout << sol("hello   world") << endl; // "hello   world"
    cout << sol("  walks  udp package   into  bar a") << endl; // "walks  udp  package  into  bar  a "
    cout << sol("a") << endl; // "a"
}
