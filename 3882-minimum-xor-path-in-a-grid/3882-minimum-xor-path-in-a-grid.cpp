class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int xr , vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            return xr;
        }

        if(dp[i][j][xr] != -1)return dp[i][j][xr];

        int ans = INT_MAX;

        if (j + 1 < n) {
            ans = min(ans, solve(grid, i, j + 1, xr , dp));
        }

        if (i + 1 < m) {
            ans = min(ans, solve(grid, i + 1, j, xr , dp));
        }

        return dp[i][j][xr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int maxXor = 1024; 
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(maxXor , -1)));
        return solve(grid, 0, 0, 0 , dp);
    }
};