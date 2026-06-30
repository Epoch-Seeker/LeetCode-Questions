class Solution {
public:
    void dfs(int node , int parent , int& timer , vector<int>& disc , vector<int>& low , vector<vector<int>>& adj , vector<vector<int>>& res){
        disc[node] = low[node] = timer++;

        for(auto nbr : adj[node]){
            if(nbr == parent)continue;

            // Not visited
            if(disc[nbr] == -1){
                dfs(nbr , node , timer , disc , low , adj , res);
                low[node] = min(low[node] , low[nbr]);

                if(low[nbr] > disc[node]){
                    vector<int> ans = {node , nbr};
                    res.push_back(ans);
                }
            }

            else {
                low[node] = min(low[node] , disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> disc(n ,-1);
        vector<int> low(n, -1);
        int timer = 0;
        int parent = -1;

        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            if(disc[i] == -1){
                dfs(i , parent , timer , disc , low , adj , res);
            }
        }

        return res;
    }
};