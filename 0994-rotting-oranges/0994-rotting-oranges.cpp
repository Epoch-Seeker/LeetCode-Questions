class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;

        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        for(int i=0;i<m ; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;

        vector<pair<int , int>> dr = {{0, -1} , {0, 1} , {1 , 0} , {-1 , 0}};

        while(!q.empty() && fresh > 0){
            
            int sz = q.size();

            while(sz--){
                auto v = q.front();
                q.pop();

                int i= v[0];
                int j= v[1];

                for(auto d : dr){
                    int x = i + d.first;
                    int y = j + d.second;

                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 ){
                        q.push({x , y});
                        grid[x][y] = 2;
                        fresh--;
                    }
                }
            }

            time++;

        }

        if(fresh)return -1;

        return time;
    }
};