class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& num : nums){
            num = abs(num);
        }
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int k = n/2;
        if(n % 2 != 0)k++;
        long long ans = 0;

        int j=n-1;
        while(j >=0){
            if(k){
                ans +=(long long)nums[j]*nums[j];
                k--;
            }else ans -= (long long)nums[j]*nums[j];
            j--;
        }

        return ans;
    }
};