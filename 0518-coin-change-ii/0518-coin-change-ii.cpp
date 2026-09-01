class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned int>> dp(amount + 1 , vector<unsigned int>(coins.size()+1 , 0));
        for(int i=0 ; i<=coins.size() ; i++ ){
            dp[0][i] = 1;
        }

        for(int am = 1 ; am <= amount ; am++){
            for(int idx = coins.size()-1 ; idx >=0 ; idx--){

                unsigned int ans = dp[am][idx+1];

                if(am - coins[idx] >= 0)
                {
                    ans += dp[am - coins[idx]][idx];
                }

                dp[am][idx] = ans;
            }
        }
        return dp[amount][0];
    }
};