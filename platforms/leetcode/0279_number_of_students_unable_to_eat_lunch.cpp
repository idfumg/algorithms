#include "../../template.hpp"

int sol(const vector<int>& students_, vector<int> sandwiches) {
    deque<int> students(students_.begin(), students_.end());
    reverse(sandwiches.begin(), sandwiches.end());
    int ans = students.size();
    int k = 0;
    while (not students.empty()) {
        if (k == students.size()) {
            break;
        }
        if (students.front() == sandwiches.back()) {
            students.pop_front();
            sandwiches.pop_back();
            --ans;
            k = 0;
        }
        else {
            students.push_back(students.front());
            students.pop_front();
            ++k;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,1,0,0}, {0,1,0,1}) << endl; // 0
    cout << sol({1,1,1,0,0,1}, {1,0,0,0,1,1}) << endl; // 3
}
