class Solution {
public:
    int twosum(vector<int>& nums, int tar, int i) {

        int l = i, r = nums.size() - 1;

        int ans = INT_MAX;
        int diff = INT_MAX;

        while (l < r) {

            int sum = nums[l] + nums[r];

            if (abs(sum - tar) < diff) {
                diff = abs(sum - tar);
                ans = sum;
            }

            if (sum < tar) {
                l++;
            }
            else if (sum > tar) {
                r--;
            }
            else {
                return tar;
            }
        }

        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int diff = INT_MAX;
        int ans ;
        int n= nums.size();
        for(int i = 0 ;i< n ; i++){
            int temp = target - nums[i];
            int k = twosum(nums , temp , i+1);
            // cout<<k<<endl;
            if(k != INT_MAX && diff > abs((nums[i] + k - target))){
                diff = abs((nums[i] + k - target));
                ans = nums[i] + k;
            }
        }
        return ans;
    }
};