#include "../../template.hpp"

int64_t sol(vector<vector<int>> rectangles) {
    for (auto& rectangle : rectangles) {
        const int w = rectangle[0];
        const int h = rectangle[1];
        const int g = std::gcd(w, h);
        rectangle[0] /= g;
        rectangle[1] /= g;
    }
    sort(rectangles.begin(), rectangles.end(), [](const auto& r1, const auto& r2){
        if (r1[0] == r2[0]) {
            return r1[1] < r2[1];
        }
        return r1[0] < r2[0];
    });
    const int n = rectangles.size();
    int64_t ans = 0;
    int64_t last = 0;
    for (int64_t i = 1; i < n; ++i) {
        if (rectangles[i] == rectangles[i - 1]) {
            ans += i - last;
        }
        else {
            last = i;
        }
    }
    return ans;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({{4,8},{3,6},{10,20},{15,30}}) << endl; // 6
    cout << sol({{4,5},{7,8}}) << endl; // 0
}
