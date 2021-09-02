#include "../../template.hpp"

int is_leap(const int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int sol(const string& s) {
    const int n = s.size();

    istringstream is(s);
    int year, month, day;
    string temp;
    getline(is, temp, '-');
    year = stoi(temp);
    getline(is, temp, '-');
    month = stoi(temp);
    getline(is, temp, '-');
    day = stoi(temp);

    const array days = {
        0,
        31,
        is_leap(year) ? 29 : 28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31,
    };

    int ans = 0;
    for (int i = 1; i < month; ++i) {
        ans += days[i];
    }
    ans += day;
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("2019-01-09") << endl; // 9
    cout << sol("2019-02-10") << endl; // 41
    cout << sol("2003-03-01") << endl; // 60
    cout << sol("2004-03-01") << endl; // 61
}
