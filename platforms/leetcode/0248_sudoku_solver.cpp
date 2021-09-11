#include "../../template.hpp"

ostream& operator<<(ostream& os, const array<int, 10>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        os << arr[i] << ' ';
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<array<int, 10>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        os << arr[i] << endl;
    }
    return os;
}

bool can_assign(vvc& board, vvc& ans, vvi& rows, vvi& cols, int row, int col, int k) {
    const int startrow = row - row % 3, startcol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startrow][j + startcol] - '0' == k) {
                return false;
            }
        }
    }
    return true;
}

void sol(vvc& board, vvc& ans, vvi& rows, vvi& cols, int row, int col) {
    const int m = board.size();
    const int n = board[0].size();

    if (row == m - 1 and col == n) {
        ans = board;
        return;
    }

    if (col == n) {
        col = 0;
        ++row;
    }

    if (board[row][col] != '.') {
        sol(board, ans, rows, cols, row, col + 1);
        return;
    }

    for (int k = 1; k <= 9; ++k) {
        if (rows[row][k] != 0) continue;
        if (cols[col][k] != 0) continue;
        if (not can_assign(board, ans, rows, cols, row, col, k)) continue;

        board[row][col] = k + '0';
        rows[row][k] = k;
        cols[col][k] = k;
        sol(board, ans, rows, cols, row, col + 1);
        board[row][col] = '.';
        rows[row][k] = 0;
        cols[col][k] = 0;
    }
}

vvc sol(vvc board) {
    const int m = board.size();
    const int n = board[0].size();

    vvi rows(m, vi(10));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != '.') {
                rows[i][board[i][j] - '0'] = board[i][j] - '0';
            }
        }
    }

    vvi cols(n, vi(10));

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (board[i][j] != '.') {
                cols[j][board[i][j] - '0'] = board[i][j] - '0';
            }
        }
    }

    vvc ans = board;
    sol(board, ans, rows, cols, 0, 0);
    return ans;
}

int main() { TimeMeasure _; //__x();
    const vvc board =
        {{'5','3','.','.','7','.','.','.','.'},
         {'6','.','.','1','9','5','.','.','.'},
         {'.','9','8','.','.','.','.','6','.'},
         {'8','.','.','.','6','.','.','.','3'},
         {'4','.','.','8','.','3','.','.','1'},
         {'7','.','.','.','2','.','.','.','6'},
         {'.','6','.','.','.','.','2','8','.'},
         {'.','.','.','4','1','9','.','.','5'},
         {'.','.','.','.','8','.','.','7','9'}};

    cout << sol(board) << endl; // 1
}
