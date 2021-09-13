#include "../../template.hpp"

vector<vector<int>> sol(vector<vector<int>> trees) {
    const auto cross = [](const auto& o, const auto& a, const auto& b) {
        return (b[1] - o[1]) * (a[0] - o[0]) - (a[1] - o[1]) * (b[0] - o[0]);
    };

    const auto cmp = [](const auto& a, const auto& b) {
        return a[0] < b[0] or (a[0] == b[0]) and a[1] < b[1];
    };

    const auto equal = [](const auto& a, const auto& b) {
        return a[0] == b[0] and a[1] == b[1];
    };

    const auto hull = [&](auto i, const auto end) {
        vector<vector<int>> H;
        for (; i != end; ++i) {
            while (H.size() >= 2 and cross(H[H.size() - 2], H[H.size() - 1], *i) < 0) {
                H.pop_back();
            }
            H.push_back(*i);
        }
        return H;
    };

    sort(trees.begin(), trees.end(), cmp);

    auto H = hull(trees.begin(), trees.end()); // lower
    for (const auto& v : hull(trees.rbegin(), trees.rend())) H.push_back(v); // upper

    sort(H.begin(), H.end(), cmp);
    H.erase(unique(H.begin(), H.end(), equal), H.end());

    return H;
}

int main() { TimeMeasure _; __x();
    cout << sol({{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}) << endl; // [[1,1],[2,0],[3,3],[2,4],[4,2]]
    cout << sol({{1,2},{2,2},{4,2}}) << endl; // [[4,2],[2,2],[1,2]]
    cout << sol({{3,7},{6,8},{7,8},{11,10},{4,3},{8,5},{7,13},{4,13}}) << endl; // [[4,13],[4,3],[3,7],[8,5],[11,10],[7,13]]
}
