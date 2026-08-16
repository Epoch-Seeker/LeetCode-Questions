class Solution {
public:
    bool dfs(vector<vector<int>>& graph , int node, vector<int>& state){
        // if node is safe
        if(state[node] == 2)return true;
        // if node is already visited -> cycle detected
        if(state[node] == 1)return false;

        state[node] = 1;

        for(auto nbr : graph[node]){
            // if nbr is unsafe
            if(!dfs(graph , nbr , state))return false;
        }

        state[node] = 2;

        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;

        int n = graph.size();

        vector<int> state(n , 0);

        for(int i=0;i< graph.size() ; i++){
            if(dfs(graph , i , state))ans.push_back(i);
        }

        return ans;
    }
};