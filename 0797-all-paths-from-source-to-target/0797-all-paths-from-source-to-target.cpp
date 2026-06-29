class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<vector<int>>& ans , int strt , vector<int>& temp , int tar){

        if(strt == tar){
            ans.push_back(temp);
        }

        for(auto i : adj[strt]){
             
                temp.push_back(i);
                dfs(adj , ans , i , temp , tar);
                temp.pop_back();
        }

        // temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        int n = graph.size();

        temp.push_back(0);

        dfs(graph , ans , 0 , temp , n-1);

        return ans;
    }
};