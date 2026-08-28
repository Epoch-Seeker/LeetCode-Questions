class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid , int i , int j , vector<vector<int>>& dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i == m-1 && j== n-1){
            if(!obstacleGrid[m-1][n-1])return 1;
            else return 0;
        };

        if(dp[i][j] != -1)return dp[i][j];

        // if(i >=m || j >= n)return 0;

        int right = j+1 < n ? obstacleGrid[i][j+1] : 1;
        int down = i+1 < m ? obstacleGrid[i+1][j] : 1;

        if(!right && !down){
            return dp[i][j] = solve(obstacleGrid , i , j+1 , dp) + solve(obstacleGrid , i+1 , j , dp);
        }else if(right && !down)return dp[i][j] = solve(obstacleGrid , i+1 , j ,dp);
        else if(!right && down)return dp[i][j] =  solve(obstacleGrid , i , j+1 , dp); 

        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    
        if(obstacleGrid[0][0] == 1)return 0;
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(obstacleGrid , 0 , 0 , dp);
    }
};