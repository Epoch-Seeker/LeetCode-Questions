class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n , vector<int> (m , INT_MAX));

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

        pq.push({0 , 0 ,0 });
        effort[0][0] = 0;

        vector<pair<int , int>> dr = {{-1 ,0 } , {1 ,0} , {0 ,-1} , {0,1}};

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int eff = t[0];
            int i = t[1];
            int j = t[2];

            if(effort[i][j] < eff)continue;

            for(auto d : dr){
                int x = i + d.first;
                int y = j + d.second;

                if(x <0 || x >= n || y <0 || y >= m)continue;

                int cur_eff = max(eff , abs(heights[i][j] - heights[x][y]));

                if( cur_eff < effort[x][y]){
                    effort[x][y] = cur_eff;
                    pq.push({cur_eff , x , y});
                }
            }
        }

        return effort[n-1][m-1];
    }
};