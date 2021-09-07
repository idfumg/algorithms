#include "../../template.hpp"

string sol(const string& s, const int k) {
    vector<string> words;
    string word;
    istringstream is(s);
    while (is >> word) {
        words.push_back(word);
    }
    while (words.size() > k) words.pop_back();
    string ans;
    for (int i = 0; i < words.size(); ++i) {
        ans += words[i];
        if (i != words.size() - 1) ans += ' ';
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol("Hello how are you Contestant", 4) << endl; // "Hello how are you"
    cout << sol("What is the solution to this problem", 4) << endl; // "What is the solution"
    cout << sol("chopper is not a tanuki", 5) << endl; // "chopper is not a tanuki"
}
