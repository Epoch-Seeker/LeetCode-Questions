class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0;
        int ans = 0;

        for(int r = 0;r<nums.size() ; r++){
            if(nums[r] == 0){
                if( k > 0) k--;
                else{
                    while(nums[l]!=0)l++;
                    l++;
                }
                
            }
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};