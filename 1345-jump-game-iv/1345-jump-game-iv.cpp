class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int , queue<int>> mp;

        for(int i=0;i<arr.size() ; i++){
            mp[arr[i]].push(i);
        }

        // for(auto& a:mp){
        //     a.second.pop();
        // }

        // for(auto a : mp){
        //     cout<<a.first<<" ";
        //     while(!a.second.empty()){
        //         cout<<a.second.front()<<" ";
        //         a.second.pop();
        //     }
        //     cout<<endl;
        // }

        queue<pair<int , int>> q;
        q.push({0 , 0});

        vector<bool> vis(n , false);
        vis[0] = true;

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t.first;
            int jump = t.second;

            // cout<<i << " "<<jump<<endl;

            if(i == n-1){
                return jump;
            }

            // left
            if(i > 0 && !vis[i-1]){
                vis[i-1] = true;
                q.push({i-1 , jump+1});
            }

            // right
            if(i < n-1 && !vis[i+1]){
                vis[i+1] = true;
                q.push({i+1 , jump+1});
            }

            // next equal
            while (!mp[arr[i]].empty()) {
                int next = mp[arr[i]].front();
                mp[arr[i]].pop();

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, jump + 1});
                }
            }
        }
        
        return -1;
    }
};