class Solution {
public:
    void solve(vector<int>& nums , long long& ans , int i , int& mn , int& mx){
        if(i>=nums.size())return;

        mn = min(mn , nums[i]);
        mx = max(mx , nums[i]);

        ans += (long long)(mx - mn);

        solve(nums ,ans , i+1 , mn , mx);
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int mn = INT_MAX;
            int mx = INT_MIN;
            solve(nums , ans , i , mn , mx);
        }
        return ans;
    }
};