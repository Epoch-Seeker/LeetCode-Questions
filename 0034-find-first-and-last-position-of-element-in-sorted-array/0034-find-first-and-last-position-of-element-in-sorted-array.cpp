class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int  m = l + (r-l)/2;

            if(nums[m] < target)l = m+1;
            else r = m-1;
        }
        return l;
    }
    int upperbound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int  m = l + (r-l)/2;

            if(nums[m] <= target)l = m+1;
            else r = m-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerbound(nums , target);
        int u = upperbound(nums , target);
        // cout<<l<<endl;
        // cout<<u<<endl;
        if(l == u)return {-1 , -1};

        return {l , u-1};
    }
};