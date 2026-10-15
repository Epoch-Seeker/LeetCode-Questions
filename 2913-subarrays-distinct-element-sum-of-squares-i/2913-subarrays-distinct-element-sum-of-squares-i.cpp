class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;

        for(int i=0;i < n;i++){
            for(int j = i ; j < n ; j++){
                unordered_set<int> st;
                for(int k = i ; k <= j ; k++){
                    // cout<<nums[k]<<" ";
                    if(!st.count(nums[k])){
                        st.insert(nums[k]);
                    }
                }
                int p = st.size();
                ans += p*p;
            }
        }

        return ans;
    }
};