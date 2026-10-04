class Solution {
public:
    bool solve(string& s , int i , int sum , vector<vector<int>>& dp){

        if(sum < 0)return false;

        if (i == s.size())
            return sum == 0;

        if(dp[i][sum] != -1)return dp[i][sum];

        bool ans ;
        
         
        if(s[i] == '(')ans = solve(s , i+1 , sum+1 , dp);
        else if(s[i] == ')')ans = solve(s , i+1 , sum-1 , dp);
        else {
            ans = solve(s , i+1 , sum+1 , dp) || solve(s , i+1 , sum-1 , dp) || solve(s , i+1 , sum , dp);
        }

        return dp[i][sum] =  ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return solve(s , 0 , 0 , dp);
    }
};