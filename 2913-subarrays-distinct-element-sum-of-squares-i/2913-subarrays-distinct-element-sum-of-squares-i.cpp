class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;

        for(int i=0;i < n;i++){
            for(int j = i ; j < n ; j++){
                vector<bool> vis(101 , false);
                int p = 0;
                for(int k = i ; k <= j ; k++){
                    // cout<<nums[k]<<" ";
                    if(!vis[nums[k]]){
                        p++;
                        vis[nums[k]] = true;
                    }
                }
                ans += p*p;
            }
        }

        return ans;
    }
};