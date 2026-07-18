class Solution {
public:
    int solve(vector<vector<int>>& grid , int m , int n){
        vector<vector<int>> dp(m+1 , vector<int> (n+1 , INT_MAX));
        
        dp[m-1][n-1] = grid[m-1][n-1];

        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1; j>=0 ; j--){
                 

                int ans = min(dp[i+1][j] , dp[i][j+1]);
                if(ans != INT_MAX)dp[i][j] = grid[i][j] + ans;
            }
        }

        return dp[0][0];
 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid  , m , n );
    }
};