class Solution {
public:
    void dfs(vector<vector<int>>& adj ,vector<bool>& vis , int node){
        vis[node] = true;

        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(adj , vis , nbr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int ans = 0;

        vector<bool> vis(n+1 , false);

        for(int i=1 ; i <=n ; i++){
            if(!vis[i]){
                ans++;
                dfs(adj , vis , i);
            }
        }

        return ans;
    }
};