class Solution {
public:
    bool dfs(vector<vector<char>>& grid ,pair<int , int> node , pair<int , int> par, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[node.first][node.second] = true;

        vector<pair<int , int>> direct = {{0,1},{1,0},{0,-1},{-1,0}};

        for(auto d : direct){
            int ni = node.first + d.first;
            int nj = node.second + d.second;

            if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            else {
                if(grid[ni][nj] == grid[node.first][node.second]){
                    if(vis[ni][nj]){
                        if(ni == par.first && nj == par.second)continue;
                        else return true;
                    }else {
                        if(dfs(grid , {ni ,nj} , {node.first , node.second} , vis))return true;
                    }
                }
                
            }
                
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>( m , false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    bool cycle = dfs(grid , {i ,j} , {-1 , -1}, vis);
                    if(cycle)return true;
                }
            }
        }

        return false;
    }
};