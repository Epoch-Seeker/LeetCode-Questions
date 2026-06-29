class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<vector<int>>& ans , vector<bool> vis , int strt , vector<int>& temp){
        vis[strt] = true;

        // temp.push_back(strt);

        for(auto i : adj[strt]){
            if(!vis[i] && i != adj.size() -1){
                temp.push_back(i);
                dfs(adj , ans , vis , i , temp);
                temp.pop_back();
            }else if(i == adj.size()-1){
                temp.push_back(i);
                ans.push_back(temp);
                temp.pop_back();
                // return;
            }
        }

        // temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        int n = graph.size();

        vector<bool> vis(n , false);

        temp.push_back(0);

        dfs(graph , ans , vis , 0 , temp);

        return ans;
    }
};