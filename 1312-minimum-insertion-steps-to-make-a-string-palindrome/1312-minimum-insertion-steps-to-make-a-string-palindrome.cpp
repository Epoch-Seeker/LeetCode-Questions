class Solution {
public:
    int solve(string& s , int i , int j , vector<vector<int>>& dp){
        if(i >= j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = solve(s , i+1 , j-1 , dp);
        }

        return dp[i][j] = 1 + min(solve(s , i+1 , j , dp) , solve(s , i , j-1 , dp));
    }
    int minInsertions(string s) {
        int i = 0 , j = s.size()-1;
        vector<vector<int>> dp(j+1 , vector<int>(j+1 , -1));
        return solve(s , i , j , dp);
    }
};