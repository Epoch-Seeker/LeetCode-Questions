class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(vector<vector<int>>& grid , int i , int j , bool down , vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1 )return 1;

        if(i > m-1 || j > n-1 )return 0;

        if(dp[i][j][down] != -1)return dp[i][j][down];

        int ans = 0;

        if(grid[i][j]){
            if(down){
                ans += solve(grid , i , j+1 , false , dp);
                ans %= mod;
            }else{
                ans += solve(grid , i+1 , j , true , dp);
                ans %= mod;
            }
        }else{
            ans += solve(grid , i+1 , j , true ,dp);
            ans %= mod;
            ans += solve(grid , i , j+1 , false , dp);
            ans %= mod;
        } 

        return dp[i][j][down] = ans;    
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(2 , -1)));
        return solve(grid , 0 , 0 , false , dp);
    }
};