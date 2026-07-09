class Solution {
public:
    void solve(vector<int>& arr , int idx ,vector<vector<int>>& ans ,vector<int>& temp){
         
        // push temp in ans
        ans.push_back(temp);
            
        for(int i=idx ; i< arr.size() ; i++){

            if(i > idx && arr[i] == arr[i-1])continue;
             
            temp.push_back(arr[i]);
            solve(arr , i +1 , ans , temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;

        sort(nums.begin() , nums.end());
        
        solve(nums , 0 , ans , temp);
        return ans;
    }
};