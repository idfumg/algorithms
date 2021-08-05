#include "../../template.hpp"

int tab(const vector<vector<char>>& arr) {
    const int m = arr.size();
    const int n = arr[0].size();

    int ans = -INF;

    vi heights(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            heights[j] = (arr[i][j] == '0') ? 0 : (heights[j] + 1);
        }

        deque<int> mq;
        vi left(n);
        for (int k = 0; k < n; ++k) {
            while (not mq.empty() and heights[k] <= heights[mq.back()]) {
                mq.pop_back();
            }
            if (mq.empty()) left[k] = -1;
            else left[k] = mq.back();
            mq.push_back(k);
        }

        mq.clear();
        vi right(n);
        for (int k = n - 1; k >= 0; --k) {
            while (not mq.empty() and heights[k] <= heights[mq.back()]) {
                mq.pop_back();
            }
            if (mq.empty()) right[k] = n;
            else right[k] = mq.back();
            mq.push_back(k);
        }

        for (int k = 0; k < n; ++k) {
            const int width = right[k] - left[k] - 1;
            const int height = heights[k];
            const int area = min(width, height);
            ans = max(ans, area * area);
        }
    }

    return ans;
}

int main() { TimeMeasure _; __x();
    const vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    cout << tab(matrix1) << endl; // 4

    const vector<vector<char>> matrix2 = {
        {'0','1'},
        {'1','0'},
    };

    cout << tab(matrix2) << endl; // 1

    const vector<vector<char>> matrix3 = {
        {'0'},
    };

    cout << tab(matrix3) << endl; // 0

    const vector<vector<char>> matrix4 = {
        {'1'},
        {'1'},
    };

    cout << tab(matrix4) << endl; // 1

    const vector<vector<char>> matrix5 = {
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'0','0','0','0','0'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
    };

    cout << tab(matrix5) << endl; // 4
}
