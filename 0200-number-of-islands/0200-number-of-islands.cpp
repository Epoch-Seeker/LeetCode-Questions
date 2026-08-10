class Solution {
public:
    void dfs(vector<vector<char>>& grid , int i , int j){
        grid[i][j] = '0';

        vector<pair<int , int>> dr = {{-1 , 0 } , {1 , 0} , {0 , -1} , {0 , 1}};

        for(auto d : dr){
            int x = i + d.first;
            int y = j + d.second;

            if( x >=0 && x < grid.size() && y >=0 && y < grid[0].size() && grid[x][y] == '1'){
                dfs(grid , x , y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid , i , j);
                }
            }
        }

        return ans;
    }
};