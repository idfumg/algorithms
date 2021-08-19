#include "../../template.hpp"

vi tab(const vi& arr, const int k) {
    unordered_map<int, int> elems;
    for (const int elem : arr) ++elems[elem];
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    for (const auto& [elem, count] : elems) {
        pq.push({count, elem});
    }
    vi ans;
    ans.reserve(k);
    for (int i = 0; i < k; ++i) {
        if (not pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,1,1,2,2,3}, 2) << endl; // 1,2
    cout << tab({1}, 1) << endl; // 1
    cout << tab({4,1,-1,2,-1,2,3}, 2) << endl; // -1,2
}
