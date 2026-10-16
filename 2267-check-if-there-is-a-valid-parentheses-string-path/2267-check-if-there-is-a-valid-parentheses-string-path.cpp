class Solution {
public:
    bool solve(vector<vector<char>>& grid , int i , int j , int sum , vector<vector<vector<int>>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            if(grid[i][j] == '(')sum++;
            else sum--;

            if(sum == 0)return true;
            return false;
        }

        if( i >= grid.size() || j >= grid[0].size())return false;

        

        if(grid[i][j] == '(')sum++;
        else sum--;

        if(dp[i][j][sum + 200] != -1)return dp[i][j][sum + 200];

        if (sum < 0) return dp[i][j][sum + 200] = false;

        return dp[i][j][sum + 200] = solve(grid , i+1 , j , sum , dp) || solve(grid , i , j+1 , sum , dp);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        // int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int> (405 , -1)));
        return solve(grid , 0 , 0 , 0 , dp);
    }
};