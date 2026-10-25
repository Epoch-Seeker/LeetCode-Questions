class Solution {
public:
    bool dfs(vector<vector<int>>& grid , int i , int j , vector<vector<bool>>& vis){
        vis[i][j] = true;

        vector<pair<int, int>> dr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        bool ans = true;

        for(auto d : dr){
            int x = i + d.first;
            int y = j + d.second;

            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
                ans = false;
                continue;
            }
            if(!grid[x][y] && !vis[x][y]){
                if(!dfs(grid , x , y , vis))ans = false;
            }
                
        }

        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
         
        int ans = 0;

        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(!grid[i][j] && !vis[i][j]){
                    if(dfs(grid , i , j , vis))ans++;
                }
            }
        }

        return ans;

    }
};