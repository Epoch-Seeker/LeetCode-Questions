class Solution {
public:
    int solve(vector<int>& nums , int i , vector<int>& dp){
        if(i >= nums.size()-1)return 0;

        if(dp[i] != -1)return dp[i];

        int ans = INT_MAX;

        for(int k = i+1; k <= i + nums[i]; k++ ){
            int temp = solve(nums , k , dp);
            if(temp != INT_MAX)
                ans = min(ans , 1 + temp);
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return solve(nums , 0 , dp);
    }
};