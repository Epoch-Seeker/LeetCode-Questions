class Solution {
public:

    int solve(vector<int>& nums, int target , int i){
        if(target == 0 && i == nums.size())return 1;

        if(i >= nums.size())return 0;

        return solve(nums , target + nums[i] , i+1) + solve(nums , target - nums[i] , i+1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
    }
};