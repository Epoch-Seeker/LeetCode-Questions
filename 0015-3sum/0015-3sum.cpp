class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        map<vector<int> , bool> mp;

        int n = nums.size();

        vector<vector<int>> ans;
         
        for(int i=0; i< n-2 ;i++){
            for(int j = i+1; j < n-1 ; j++){
                int temp = - (nums[i] + nums[j]);
                auto it = lower_bound(nums.begin()+j+1 , nums.end() , temp);
                if( it != nums.end()  && *it == temp){
                    if(!mp[{nums[i] , nums[j] , temp}]){
                        ans.push_back({nums[i] , nums[j] , temp});
                        mp[{nums[i] , nums[j] , temp}] = true;
                    }
                    
                }
            }
        }

        return ans;

    }
};