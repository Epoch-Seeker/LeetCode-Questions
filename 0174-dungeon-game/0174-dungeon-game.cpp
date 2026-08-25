class Solution {
public:
    int solve(vector<vector<int>>& dungeon , int i , int j , vector<vector<int>>& dp){
        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i >= m|| j >= n)return INT_MAX;

        if(i == m-1 && j == n-1)return max(1 , 1 - dungeon[i][j]);

        if(dp[i][j] != -1)return dp[i][j];

        int down = solve(dungeon , i+1 , j , dp);
        int right = solve(dungeon , i , j+1 , dp);

        int need = min(down , right);

        return dp[i][j] = max(1 , need - dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(dungeon ,0, 0 , dp);
    }
};