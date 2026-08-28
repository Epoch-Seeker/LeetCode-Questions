class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid){
        

         

        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)return 0;
        vector<vector<long long>> dp(m , vector<long long>(n , 0));

        dp[m-1][n-1] = 1;

        for(int i = m-1 ;i>=0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i== m-1 && j == n-1)continue;

                // Current cell is an obstacle
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                long long right = (j + 1 < n) ? dp[i][j+1] : 0;
                long long down  = (i + 1 < m) ? dp[i+1][j] : 0;

                dp[i][j] = (long long)(right + down);

            }
        }

        return dp[0][0];
    }
};