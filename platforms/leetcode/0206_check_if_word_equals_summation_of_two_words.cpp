#include "../../template.hpp"

int sol(const string& a, const string& b, const string& c) {
    string ar;
    for (const char ch : a) {
        ar += to_string(ch - 'a');
    }
    string br;
    for (const char ch : b) {
        br += to_string(ch - 'a');
    }
    string cr;
    for (const char ch : c) {
        cr += to_string(ch - 'a');
    }
    return stoi(ar) + stoi(br) == stoi(cr);
}

int main() { TimeMeasure _; //__x();
    cout << sol("acb", "cba", "cdb") << endl; // 1
    cout << sol("aaa", "a", "aab") << endl; // 0
    cout << sol("aaa", "a", "aaaa") << endl; // 1
}
