
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Store queries with their original indices
        vector<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m);
        unordered_map<int,int> freq;

        int l = 0, r = 0;
        int active = 0;

        for(auto &[t, idx] : q) {

            // Add logs whose time <= t
            while(r < logs.size() && logs[r][1] <= t) {
                int id = logs[r][0];

                if(freq[id] == 0) active++;
                freq[id]++;

                r++;
            }

            // Remove logs whose time < t - x
            while(l < r && logs[l][1] < t - x) {
                int id = logs[l][0];

                freq[id]--;

                if(freq[id] == 0) active--;

                l++;
            }

            // Servers with zero requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
