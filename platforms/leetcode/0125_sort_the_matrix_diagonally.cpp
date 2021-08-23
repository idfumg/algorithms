#include "../../template.hpp"

vvi tab(vvi mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    for (int i = 0; i < m; ++i) {
        vi arr;
        for (int j = 0, k = i; j < n and k < m; ++j, ++k) {
            arr.push_back(mat[k][j]);
        }
        sort(arr.begin(), arr.end());
        for (int j = 0, k = i, idx = 0; j < n and k < m; ++j, ++k, ++idx) {
            mat[k][j] = arr[idx];
        }
    }
    for (int j = 1; j < n; ++j) {
        vi arr;
        for (int i = 0, k = j; i < m and k < n; ++i, ++k) {
            arr.push_back(mat[i][k]);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0, k = j, idx = 0; i < m and k < n; ++i, ++k, ++idx) {
            mat[i][k] = arr[idx];
        }
    }
    return mat;
}

int main() { TimeMeasure _; __x();
    cout << tab({{3,3,1,1},{2,2,1,2},{1,1,1,2}}) << endl; //
}
