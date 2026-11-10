class Solution {
public:
    int solve(int i , int n , vector<int>& costs , vector<int>& dp){
        if(i >= n)return 0;

        if(dp[i] != -1)return dp[i];

        int ans = INT_MAX;

        ans = min(ans , costs[i] + 1 + solve(i+1 , n , costs, dp));
        if(i+1 < n)
            ans = min(ans , costs[i+1] + 4 + solve(i+2 , n , costs, dp));
        if(i+2 < n)
            ans = min(ans , costs[i+2] + 9 + solve(i+3 , n , costs, dp));

        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n , -1);
        return solve(0 , n , costs, dp);
    }
};