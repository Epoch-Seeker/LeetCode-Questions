class Solution {
public:
    int solve(vector<vector<int>>& triangle , int level , int i , vector<vector<int>>& dp){
        if(level >= triangle.size())return 0;

        if(level == triangle.size()-1)return triangle[level][i];

        if(dp[level][i] != INT_MAX)return dp[level][i];

        int left = solve(triangle , level+1 , i , dp);
        int right = solve(triangle , level+1 , i+1 , dp);

        return dp[level][i] = triangle[level][i] + min(left , right);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);

        for(int i=0;i<m;i++){
            dp[i].resize(triangle[i].size() , INT_MAX);
        }
        return solve(triangle , 0 , 0 , dp);
    }
};