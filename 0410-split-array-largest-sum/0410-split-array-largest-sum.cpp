class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin() , nums.end());
        long long h = accumulate(nums.begin() , nums.end() , 0LL);

        long long ans = -1;

        while(l <= h){

            long long m = l + (h - l)/2;

            long long sum = 0;
            long long subarray = 1;

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