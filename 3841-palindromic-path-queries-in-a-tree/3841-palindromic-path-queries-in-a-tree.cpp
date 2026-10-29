class Solution {
    struct FenwickXor {
        int n;
        vector<int> bit;

        FenwickXor(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        int query(int idx) {
            int res = 0;

            for (int i = idx + 1; i > 0; i -= i & -i) {
                res ^= bit[i];
            }

            return res;
        }

        void rangeXor(int l, int r, int val) {
            add(l, val);

            if (r + 1 < n) {
                add(r + 1, val);
            }
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<int> parent(n, 0), depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> basePrefix(n, 0), order;
        vector<int> st;

        order.reserve(n);
        st.reserve(n);

        // Iterative DFS: establish Euler order and root-prefix masks.
        st.push_back(0);

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = (int)order.size();
            order.push_back(u);

            basePrefix[u] =
                (u == 0 ? 0 : basePrefix[parent[u]])
                ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v == parent[u]) {
                    continue;
                }

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        // Compute subtree sizes in reverse DFS order.
        vector<int> subSize(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            subSize[parent[u]] += subSize[u];
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + subSize[u] - 1;
        }

        // Binary lifting table for LCA.
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        auto lca = [&](int a, int b) -> int {
            if (depth[a] < depth[b]) {
                swap(a, b);
            }

            int diff = depth[a] - depth[b];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    a = up[k][a];
                }
            }

            if (a == b) {
                return a;
            }

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }

            return parent[a];
        };

        FenwickXor fw(n);
        vector<bool> ans;

        for (const string& str : queries) {
            stringstream ss(str);

            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                // Every root-prefix mask in u's subtree changes.
                fw.rangeXor(tin[u], tout[u], delta);

                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int prefixU =
                    basePrefix[u] ^ fw.query(tin[u]);

                int prefixV =
                    basePrefix[v] ^ fw.query(tin[v]);

                // Include the LCA exactly once.
                int mask = prefixU ^ prefixV
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};