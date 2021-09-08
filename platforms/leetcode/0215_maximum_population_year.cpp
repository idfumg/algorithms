#include "../../template.hpp"

int sol(const vvi& arr) {
    array<int, 2051> lives{};
    for (const vi& life : arr) {
        ++lives[life[0]];
        --lives[life[1]];
    }
    int maxi = 0;
    int ans = 0;
    int current = 0;
    for (int i = 1950; i < lives.size(); ++i) {
        current += lives[i];
        if (maxi < current) {
            maxi = current;
            ans = i;
        }
    }
    return ans;
}

int main() { TimeMeasure _; //__x();
    cout << sol({{1993,1999},{2000,2010}}) << endl; // 1993
    cout << sol({{1950,1961},{1960,1971},{1970,1981}}) << endl; // 1960
    cout << sol({{2033,2034},{2039,2047},{1998,2042},{2047,2048},{2025,2029},{2005,2044},{1990,1992},{1952,1956},{1984,2014}}) << endl; // 2005
    cout << sol({{1987,2047},{1952,2006},{2021,2042},{2047,2049},{2036,2040},{1994,2009}}) << endl; // 1994
    cout << sol({{2008,2026},{2004,2008},{2034,2035},{1999,2050},{2049,2050},{2011,2035},{1966,2033},{2044,2049}}) << endl; // 2011
}
