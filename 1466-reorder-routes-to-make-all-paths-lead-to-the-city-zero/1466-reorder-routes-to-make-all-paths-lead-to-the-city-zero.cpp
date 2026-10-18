class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj,
             int node, int parent, int& ans) {

        for (auto [nbr, cost] : adj[node]) {
            if (nbr == parent) continue;

            ans += cost;
            dfs(adj, nbr, node, ans);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : connections) {
            int u = e[0], v = e[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int ans = 0;
        dfs(adj, 0, -1, ans);

        return ans;
    }
};