class Solution {
public:

    int solve(vector<int>& nums, int target , int i ,vector<vector<int>>& dp){
        if(target == 0 && i == nums.size())return 1;

        if(i >= nums.size())return 0;

        if(dp[target+3000][i] != -1)return dp[target+3000][i];

        return dp[target+3000][i] = solve(nums , target + nums[i] , i+1 , dp) + solve(nums , target - nums[i] , i+1 , dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(target + 6000 , vector<int>(n , -1));
        return solve(nums , target , 0 , dp);
    }
};