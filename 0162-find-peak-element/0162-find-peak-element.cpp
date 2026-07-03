class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;

        while(l<=h){
            int m = l + (h - l)/2;

            if(m-1>=0){
                if(nums[m] > nums[m-1]){
                    if(m+1 < nums.size()){
                        if(nums[m] > nums[m+1]){
                            return m;
                        }else l = m + 1;
                    }else return m;
                }else h= m-1;
            }else {
                if(m+1 < nums.size()){
                    if(nums[m] > nums[m+1]){
                        return m;
                    }else l = m+1;
                }else return m;
            }
            
        }

        return 0;
    }
};