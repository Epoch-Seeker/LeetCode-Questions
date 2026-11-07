
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available: {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        // Busy: {available_time, weight, index}
        priority_queue<vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>> busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            // Move all free servers into available heap
            while(!busy.empty() && busy.top()[0] <= time) {
                auto t = busy.top();
                busy.pop();

                available.push({t[1], t[2]});
            }

            // If no server is available, jump to earliest free time
            if(available.empty()) {
                time = busy.top()[0];

                while(!busy.empty() && busy.top()[0] <= time) {
                    auto t = busy.top();
                    busy.pop();

                    available.push({t[1], t[2]});
                }
            }

            // Select best available server
            auto t = available.top();
            available.pop();

            int weight = t.first;
            int idx = t.second;

            ans.push_back(idx);

            // Assign task and mark server busy
            busy.push({
                time + tasks[i],
                weight,
                idx
            });
        }

        return ans;
    }
};
