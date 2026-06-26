class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, diag1, diag2;
    int n;

    void backtrack(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            board[row][c] = 'Q';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;

            backtrack(row + 1);

            board[row][c] = '.';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;

        board.assign(n, string(n, '.'));

        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        backtrack(0);

        return ans;
    }
};