class Solution {
public:
    void dfs(vector<int>& adj ,vector<bool>& vis ,vector<bool>& pathvis, int node , vector<int>& temp , int& p){
        vis[node] = true;
        pathvis[node] = true;

        if(adj[node] != -1){
            if(!vis[adj[node]]){
                temp[adj[node]] = temp[node] + 1;
                dfs(adj , vis  , pathvis , adj[node] , temp , p);
            }
            else {

                if(pathvis[adj[node]]){
                    p = max(p , temp[node] - temp[adj[node]] + 1);
                }

            }
        }

        pathvis[node] = false;

        // cout<<pathvis[node]<<" ";
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n , false);
        vector<int> temp(n , 0);
        vector<bool> pathvis(n , false);

        int ans = -1;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(edges , vis , pathvis , i , temp , ans);
                // cout<<ans<<" ";
            }
        }

        return ans;
    }
};