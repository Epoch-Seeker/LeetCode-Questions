class Solution {
public:
    bool solve(string word , vector<vector<char>>& board , int idx , int i , int j , vector<vector<bool>>& vis){
        if(idx == word.size())return true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size() &&
                !vis[nr][nc] &&
                board[nr][nc] == word[idx]) {

                vis[nr][nc] = true;

                if (solve(word, board, idx + 1, nr, nc, vis))
                    return true;

                vis[nr][nc] = false;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {

        
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m , vector<bool> (n , false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(solve(word , board , 1 , i , j , vis))return true;
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};