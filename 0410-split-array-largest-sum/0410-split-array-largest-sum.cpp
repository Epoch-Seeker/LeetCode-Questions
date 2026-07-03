class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin() , nums.end());
        int h = accumulate(nums.begin() , nums.end() , 0LL);

        int ans = -1;

        while(l <= h){

            int m = l + (h - l)/2;

            int sum = 0;
            int subarray = 1;

            for(auto i : nums){
                if(sum + i > m){
                    subarray++;
                    sum = i;
                }else sum += i;
            }

            if(subarray <= k){
                ans = m;
                h = m -1;
            }
            else l = m + 1;
        }

        return ans;
    }
};