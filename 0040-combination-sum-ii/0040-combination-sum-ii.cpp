
class Solution {
public:
    void solve(vector<int>& cands, int t , vector<vector<int>>& ans , vector<int>& temp , int idx ){
        if(t == 0){
             
            ans.push_back(temp);
             
            return;
        }

        for(int i = idx ; i < cands.size() ; i++){
            if(i > idx && cands[i] == cands[i-1])continue;
            if( t - cands[i] >= 0){
                temp.push_back(cands[i]);
                solve(cands , t - cands[i] , ans , temp , i +1);
                temp.pop_back();
        
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        solve(candidates ,target , ans , temp , 0);
        return ans;
    }
};