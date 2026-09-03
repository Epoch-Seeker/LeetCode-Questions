class Solution {
public:
    bool canJump(vector<int>& nums) {
        int temp = nums[0];

        int i = 0;

        while(temp > 0 && i < nums.size()-1){
            temp--;
            i++;
            temp = max(temp , nums[i]);
        }

        if(i == nums.size()-1)return true;
        return false;
    }
};