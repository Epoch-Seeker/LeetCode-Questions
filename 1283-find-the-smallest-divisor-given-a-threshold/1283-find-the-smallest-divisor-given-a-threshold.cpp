class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            // check mid can be answer or not
            long long temp = 0;

            for(auto num : nums){
                temp += (num + mid - 1) / mid;
            }

            if(temp <= threshold){
                ans = mid;
                high = mid - 1;
            }else low = mid +1;
        }

        return ans;
        
    }
};