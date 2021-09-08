#include "../../template.hpp"

int sol(const string& s) {
    const int row = s[0] - 'a';
    const int column = s[1] - '0';
    vvi board(10, vi(10));
    for (int i = 1; i <= 8; ++i) {
        int color = i & 1;
        for (int j = 1; j <= 8; ++j) {
            board[i][j] = color;
            color = 1 - color;
        }
    }
    return board[row + 1][column] == 0;
}

int main() { TimeMeasure _; //__x();
    cout << sol("a1") << endl; // 0
    cout << sol("h3") << endl; // 1
    cout << sol("c7") << endl; // 0
    cout << sol("a8") << endl; // 1
}
