//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    string s; is >> s;

    unordered_set<string> words;
    for (string word : {"dream", "dreamer", "erase", "eraser"}) {
        reverse(word.begin(), word.end());
        words.insert(word);
    }

    string current;
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        current += s[i];
        if (words.count(current)) {
            current.clear();
        }
    }
    if (current.empty()) cout << "YES";
    else cout << "NO";
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
erasedream
)",
        R"(
dreameraser
)",
        R"(
dreamerer
)"
    };

    for (const auto& input : inputs) {
        istringstream is(input);
        sol(is);
        cout << endl;
    }
}

#else

int main() {
    sol(std::cin);
}

#endif // LOCAL_MACHINE
