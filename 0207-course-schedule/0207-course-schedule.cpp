class Solution {
public:
    bool cycle(vector<vector<int>>& adj , vector<bool>& vis , vector<bool>& pathVis , int node){
        vis[node] = true;
        pathVis[node] = true;

        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(cycle(adj , vis , pathVis , nbr))return true;
            }
            else {
                if(pathVis[nbr])return true;
            }
        }

        pathVis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto e : prerequisites){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses , false);
        vector<bool> pathVis(numCourses , false);

        for(int i=0;i< numCourses ; i++){
            if(!vis[i]){
                if(cycle(adj , vis  , pathVis , i))return false;
            }
        }

        return true;
    }
};