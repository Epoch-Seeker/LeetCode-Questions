class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        int avg = 0;
        sort(nums.begin() , nums.end());

        if(n % 2 == 0){
            avg = (nums[n/2 - 1] + nums[n/2]) / 2;
        }else avg = nums[n/2];

        int ans = 0;

        for(int i : nums){
            ans += abs(i - avg);
        }

        return ans;
    }
};