class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int temp = 1;
        if(nums.size() == 1)return ans;

        int inc = 0;
        if(nums[1] > nums[0]){
            inc = 1;
            temp++;
        }
        else if(nums[1] < nums[0]){
            inc = -1;
            temp++;
        }

        ans = max(ans , temp);

        for(int i = 2 ; i< nums.size(); i++){
            if(nums[i] > nums[i-1]){
                if(inc != 1){
                    temp = 2;
                    inc = 1;
                }
                else temp++;
            }else if(nums[i] < nums[i-1]){
                if(inc != -1){
                    temp = 2;
                    inc = -1;
                }
                else temp++;
            }else inc = 0;

            ans = max(ans , temp);
        }

        return ans;
    }
};