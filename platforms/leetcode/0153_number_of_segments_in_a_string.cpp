#include "../../template.hpp"

int sol(const string& s) {
    int ans = 0;
    string word;
    istringstream is(s);
    while (is >> word) {
        ++ans;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("Hello, my name is John") << endl; // 5
    cout << sol("Hello") << endl; // 1
    cout << sol("love live! mu'sic forever") << endl; // 4
    cout << sol("") << endl; // 0
}
