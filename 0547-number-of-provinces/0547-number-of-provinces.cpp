class Solution {
public:
    void dfs(vector<vector<int>>& isConnected ,vector<bool>& vis , int node){
        vis[node] = true;

        for(int nbr = 0 ; nbr< isConnected.size() ; nbr++){
            if(isConnected[node][nbr] && !vis[nbr]){
                dfs(isConnected , vis , nbr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        int ans = 0;

        vector<bool> vis(n, false);

        for(int i= 0; i <n ; i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected , vis , i);
            }
        }

        return ans;
    }
};