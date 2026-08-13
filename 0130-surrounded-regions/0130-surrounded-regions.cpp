class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j , vector<pair<int , int>>& temp, bool& flag, vector<vector<bool>>& vis){
        vis[i][j] = true;
        temp.push_back({i,j});

        int dx[] = {-1 , 1, 0, 0};
        int dy[] = {0 , 0, -1, 1};

        for(int k = 0 ;k< 4 ; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()){
                flag = true;
                continue;
            }

            if(vis[x][y] || board[x][y] == 'X')continue;

            dfs(board , x , y , temp , flag , vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        
        vector<vector<pair<int , int>>> v;

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m , vector<bool>(n , false));

        for(int i=0;i< m ; i++){
            for(int j = 0 ;j < n ; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    vector<pair<int , int>> temp;
                    bool flag = false;
                    dfs(board , i , j , temp , flag , vis);
                    if(!flag){
                        v.push_back(temp);
                    }
                }
            }
        }

        for(auto t : v){
            for(auto s : t){
                board[s.first][s.second] = 'X';
            }
        }
    }
};