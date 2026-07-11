class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0;
        int ans = 0;
        int p = k;
        for(int r = 0;r<nums.size() ; r++){
            if(nums[r] == 0){
                if( p > 0) p--;
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