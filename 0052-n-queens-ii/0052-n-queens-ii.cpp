class Solution {
public:
    int ans = 0;
    vector<int> col, diag1, diag2;
    int n;

    void backtrack(int row) {
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;

            backtrack(row + 1);

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
        }
    }

    int totalNQueens(int N) {
        n = N;

        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        backtrack(0);

        return ans;
    }
};