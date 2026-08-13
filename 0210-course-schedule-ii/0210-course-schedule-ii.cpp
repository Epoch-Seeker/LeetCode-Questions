class Solution {
public:
    bool dfs(vector<vector<int>>& adj , int node , vector<int>& ans, vector<bool>& vis , vector<bool>& pathVis){
        vis[node] = true;
        pathVis[node] = true;

        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(dfs(adj , nbr , ans , vis,pathVis ))return true;
            }else if(pathVis[nbr]){
                return true;
            }
        }
        pathVis[node] = false;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto e : prerequisites){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
        }

        vector<int> ans;
        vector<bool> vis(numCourses , false);
        vector<bool> pathVis(numCourses , false);

        for(int i = 0 ; i< numCourses ; i++){
            if(!vis[i]){
                if(dfs(adj , i , ans , vis , pathVis))return {};
            }
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};