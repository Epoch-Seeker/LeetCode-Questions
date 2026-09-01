class Solution {
public:
    int solve(int amount, vector<int>& coins , int idx , vector<vector<int>>& dp){
        if(idx >= coins.size() || amount < 0)return 0;
        if(amount == 0)return 1;

        if(dp[amount][idx] != -1)return dp[amount][idx];

        int ans = 0;

        for(int i = idx ; i< coins.size() ; i++){
            ans += solve(amount-coins[i] , coins , i , dp);
            // ans += solve(amount , coins , i+1);
        }

        return dp[amount][idx] = ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1 , vector<int>(coins.size() , -1));
        return solve(amount , coins , 0 , dp);
    }
};