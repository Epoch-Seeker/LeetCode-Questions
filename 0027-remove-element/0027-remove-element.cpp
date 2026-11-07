class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for(int& num : nums){
            if(num == val)num = 51;
            else ans++;
        }
        sort(nums.begin() , nums.end());
        return ans;
    }
};