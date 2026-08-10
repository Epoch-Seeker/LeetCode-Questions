class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int , int> mp;

        int ans = 0;

        int pre_sum = 0;

        mp[0] = 1;

        for(auto i : nums){

            pre_sum += i;

            if(mp.count(pre_sum - k))ans += mp[pre_sum - k];

            mp[pre_sum]++;
        }
        
        return ans;
    }
};