class Solution {
public:
    void solve(vector<int>& nums , set<vector<int>>& st , int idx){
        if(idx >= nums.size()){
            st.insert(nums);
            return;
        }
        for(int i = idx; i< nums.size(); i++){ 
            // if(idx != i && nums[idx] == nums[i]){
            //     solve(nums , ans, idx+1);
            //     continue;
            // }
            swap(nums[idx] , nums[i]);
            solve(nums , st, idx+1);
            swap(nums[idx] , nums[i]);       
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        solve(nums , st , 0);
        for(auto it :st)ans.push_back(it);
        return ans; 
    }
};
