class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int tar = sum - x;

        int n = nums.size();

        int l = 0;
        int temp = 0;
        int ans = INT_MAX;
        for(int r = 0 ; r < n; r++){
            temp += nums[r];

            while(temp > tar && l <= r){
                temp -= nums[l++];
            }

            if(temp == tar){
                ans = min(ans , n - (r - l + 1));
            }

            
        }

        // while(temp > tar && l < n){
        //     temp -= nums[l++];
        // }

        // if(temp == tar){
        //     ans = min(ans , l); 
        // }

        if(ans == INT_MAX)return -1;
        return ans;
    }
};