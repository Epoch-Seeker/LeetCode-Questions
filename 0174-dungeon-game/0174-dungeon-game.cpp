class Solution {
public:
    int solve(vector<vector<int>>& dungeon){
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , INT_MAX));

        // if(i >= m|| j >= n)return INT_MAX;
        dp[m-1][n-1] = max(1 , 1 - dungeon[m-1][n-1]);

        // if(i == m-1 && j == n-1)return max(1 , 1 - dungeon[i][j]);

        // if(dp[i][j] != -1)return dp[i][j];

        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1;j>=0;j--){
                if (i == m-1 && j == n-1)
                    continue;

                int down = dp[i+1][j];
                int right = dp[i][j+1];

                int need = min(down , right);

                dp[i][j] = max(1 , need - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        
        return solve(dungeon);
    }
};