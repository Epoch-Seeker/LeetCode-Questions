class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size()-1;
        if(nums[0]>0)return nums[n-2]*nums[n-1]*nums[n];

        if(nums[0]*nums[1]*nums[n] >  nums[n-2]*nums[n-1]*nums[n]){
            return nums[0]*nums[1]*nums[n];
        }

        return nums[n-2]*nums[n-1]*nums[n];

    }
};