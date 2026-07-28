class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        int a , b;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(mp[comp] > 0){
                a = comp;
                b = nums[i];
                break;
            }
            mp[nums[i]]++;
        }

        int p = -1 , q = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == a && p == -1)p=i;
            else if(nums[i] == b && q == -1)q = i;
        }

        return {p,q};
    }
};