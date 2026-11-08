class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i , int j , int& temp){
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = 0;
        temp++;

        //horizontal
        for(int k =0 ; k < n ; k++){
            if(grid[i][k])
                dfs(grid , i , k , temp);
        }
 
        //vertical
        for(int k =0 ; k < m ; k++){
            if(grid[k][j])
                dfs(grid , k , j , temp);
        }

    }
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j]){
                    int temp = 0;
                    dfs(grid , i , j , temp);
                    if(temp > 1)ans += temp;
                }
            }
        }

        return ans;
    }
};