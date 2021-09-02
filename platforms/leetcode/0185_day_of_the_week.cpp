#include "../../template.hpp"

string sol(int day, int month, int year) {
    std::tm time_in = { 0, 0, 0, day, month - 1, year - 1900 }; // 1-based day, 0-based month, year since 1900
    std::time_t time_temp = std::mktime(&time_in);
    const std::tm * time_out = std::localtime(&time_temp);
    const int current = time_out->tm_wday;
    switch (current) {
    case 0: return "Sunday";
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    };
    return "";
}

int main() { TimeMeasure _; __x();
    cout << sol(31, 8, 2019) << endl; // Saturday
    cout << sol(18, 7, 1999) << endl; // Sunday
    cout << sol(15, 8, 1993) << endl; // Sunday
}
