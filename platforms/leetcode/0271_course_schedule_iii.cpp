#include "../../template.hpp"

int sol(vvi courses) {
    sort(courses.begin(), courses.end(), [](const vi& a, const vi& b){return a[0] < b[0];});
    priority_queue<int> pq;
    const int n = courses.size();
    int total_time = 0;
    for (int i = 0; i < n; ++i) {
        const int time = courses[i][0];
        const int duration = courses[i][1];
        total_time += time;
        pq.push(time);
        if (total_time > duration) {
            total_time -= pq.top(); pq.pop();
        }
    }
    return pq.size();
}

int main() { TimeMeasure _; __x();
    cout << sol({{100,200},{200,1300},{1000,1250},{2000,3200}}) << endl; // 3
    cout << sol({{1,2}}) << endl; // 1
    cout << sol({{3,2},{4,3}}) << endl; // 0
}
