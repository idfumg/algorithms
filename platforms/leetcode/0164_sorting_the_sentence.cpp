#include "../../template.hpp"

string sol(const string& s) {
    const int n = s.size();

    string temp;
    istringstream is(s);
    vector<string> wordsx;
    while (is >> temp) wordsx.push_back(temp);

    vector<string> words(wordsx.size());
    for (const auto& word : wordsx) {
        const int idx = word.back() - '0' - 1;
        words[idx] = word;
        words[idx].pop_back();
    }

    string ans;
    for (int i = 0; i < words.size(); ++i) {
        ans += words[i];
        if (i != words.size() - 1) ans += ' ';
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("is2 sentence4 This1 a3") << endl; // This is a sentence
    cout << sol("Myself2 Me1 I4 and3") << endl; // Me Myself and I
}
