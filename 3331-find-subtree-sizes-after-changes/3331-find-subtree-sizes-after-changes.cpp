class Solution {
public:
    vector<int> ans;
    vector<int> adj[100005];
    vector<int> last[26];

    void dfs(int u, string &s) {
        int c = s[u] - 'a';

        int newParent = -1;

        if (!last[c].empty()) {
            newParent = last[c].back();
        }

        last[c].push_back(u);

        for (int v : adj[u]) {
            dfs(v, s);
        }

        last[c].pop_back();

        // Calculate subtree size
        ans[u] = 1;
        for (int v : adj[u]) {
            ans[u] += ans[v];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> newParent(n);

        vector<vector<int>> original = children;

        // Find the closest matching ancestor
        vector<int> lastSeen[26];

        function<void(int)> findParent = [&](int u) {
            int c = s[u] - 'a';

            if (!lastSeen[c].empty()) {
                newParent[u] = lastSeen[c].back();
            } else {
                newParent[u] = parent[u];
            }

            lastSeen[c].push_back(u);

            for (int v : original[u]) {
                findParent(v);
            }

            lastSeen[c].pop_back();
        };

        findParent(0);

        // Build the modified tree
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        ans.assign(n, 0);

        function<int(int)> dfs = [&](int u) {
            ans[u] = 1;

            for (int v : adj[u]) {
                ans[u] += dfs(v);
            }

            return ans[u];
        };

        dfs(0);

        return ans;
    }
};