class Solution {
public:
    void dfs(vector<vector<int>>& board , int i , int j ){
        board[i][j] = 0;

        int dx[] = {-1 , 1, 0, 0};
        int dy[] = {0 , 0, -1, 1};

        for(int k = 0 ;k< 4 ; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >=0 && x < board.size() && y>=0 && y < board[0].size() && board[x][y])dfs(board , x , y);

            
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // top
        for(int i=0;i< n ; i++){
            if(grid[0][i])dfs(grid , 0 , i);
            if(grid[m-1][i])dfs(grid , m-1 , i);
        }

        for(int i=0;i< m; i++){
            if(grid[i][0] )dfs(grid , i, 0);
            if(grid[i][n-1] )dfs(grid , i, n-1);
        }

        int ans = 0;

        for(int i=0;i< m ; i++){
            for(int j = 0 ;j < n ; j++){
                ans += grid[i][j];
            }
        }

        return ans;
    }
};