#include "../../template.hpp"

int sol(const string& name, const string& s) {
    const int m = name.size();
    const int n = s.size();
    if (name[0] != s[0]) return 0;
    int i = 0;
    int j = 0;
    while (i < m and j < n) {
        if (name[i] == s[j]) {
            ++i;
            ++j;
        }
        else {
            if (s[j] == s[j - 1]) {
                ++j;
            }
            else {
                return 0;
            }
        }
    }
    while (s[j] == s[j - 1]) ++j;
    return i == m and j == n;
}

int main() { TimeMeasure _; __x();
    cout << sol("alex", "aaleex") << endl; // 1
    cout << sol("saeed", "ssaaedd") << endl; // 0
    cout << sol("leelee", "lleeelee") << endl; // 1
    cout << sol("laiden", "laiden") << endl; // 1
    cout << sol("alexd", "ale") << endl; // 0
    cout << sol("alex", "aaleexa") << endl; // 0
    cout << sol("vtkgn", "vttkgnn") << endl; // 1
}
