class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;

        for(int i=0;i < n;i++){
            vector<bool> vis(101 , false);
            int p = 0;
            for(int j = i ; j < n ; j++){
                 
                if(!vis[nums[j]]){
                    p++;
                    vis[nums[j]] = true;
                }
                
                ans += p*p;
            }
        }

        return ans;
    }
};