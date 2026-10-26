class Solution {
public:
    long long dfs(vector<vector<int>>& grid , int i , int j){
        long long ans = grid[i][j];
        grid[i][j] = 0;

        vector<pair<int, int>> dr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : dr){
            int x = i + d.first;
            int y = j + d.second;

            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
                continue;
            }
            if(grid[x][y]){
                ans += dfs(grid , x , y);
            }
                
        }

        return ans;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(grid[i][j]){
                    if(dfs(grid , i , j) % k == 0)ans++;
                } 
            }
        }

        return ans;
    }
};