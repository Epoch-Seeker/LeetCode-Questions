class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int l = 0;
        int h = nums.size()-1;

        // if(l==h)return nums[l];

        while(l<=h){
            int m = l + (h - l)/2;

            if(m-1 >= 0 && nums[m-1] == nums[m]){
                if((h-m)%2 ==0 ){
                    h = m-2;
                }else l = m+1;
            }

            else if(m+1 < nums.size() && nums[m] == nums[m+1]){
                if(m % 2 ==0){
                    l = m +2;
                }else h = m -1;
            }

            else return nums[m];
        }

        return 0;
    }
};