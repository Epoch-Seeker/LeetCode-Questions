class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j ){
        board[i][j] = 's';

        int dx[] = {-1 , 1, 0, 0};
        int dy[] = {0 , 0, -1, 1};

        for(int k = 0 ;k< 4 ; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >=0 && x < board.size() && y>=0 && y < board[0].size() && board[x][y] == 'O')dfs(board , x , y);

            
        }
    }
    void solve(vector<vector<char>>& board) {
        
        vector<vector<pair<int , int>>> v;

        int m = board.size();
        int n = board[0].size();

        // top
        for(int i=0;i< n ; i++){
            if(board[0][i] == 'O')dfs(board , 0 , i);
            if(board[m-1][i] == 'O')dfs(board , m-1 , i);
        }

        for(int i=0;i< m; i++){
            if(board[i][0] == 'O')dfs(board , i, 0);
            if(board[i][n-1] == 'O')dfs(board , i, n-1);
        }

        for(int i=0;i< m ; i++){
            for(int j = 0 ;j < n ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 's'){
                    board[i][j] = 'O';
                }
                
            }
        }
 
    }
};