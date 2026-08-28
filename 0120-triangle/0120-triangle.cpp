class Solution {
public:
    int solve(vector<vector<int>>& triangle , int level , int i , vector<vector<int>>& dp){
        if(level >= triangle.size())return 0;

        if(dp[level][i] != INT_MAX)return dp[level][i];

        int left = solve(triangle , level+1 , i , dp);
        int right = solve(triangle , level+1 , i+1 , dp);

        return dp[level][i] = triangle[level][i] + min(left , right);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m , vector<int>(n , INT_MAX));
        return solve(triangle , 0 , 0 , dp);
    }
};