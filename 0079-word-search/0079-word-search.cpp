class Solution {
public:
    bool solve(string word , vector<vector<char>>& board , int idx , int i , int j , vector<vector<bool>>& vis){
        if(idx == word.size())return true;

        bool ans = false;

        //up
        if(i-1>=0 && !vis[i-1][j]){
            if(board[i-1][j] == word[idx]){
                vis[i-1][j] = true;
                ans = ans || solve(word , board , idx + 1 , i-1 , j , vis);
                vis[i-1][j] = false;
            }
        }

        //down
        if(i+1 < board.size() && !vis[i+1][j]){
            if(board[i+1][j] == word[idx]){
                vis[i+1][j] = true;
                ans = ans || solve(word , board , idx + 1 , i+1 , j , vis);
                vis[i+1][j] = false;
            }
        }

        //left
        if(j-1>=0 && !vis[i][j-1]){
            if(board[i][j-1] == word[idx]){
                vis[i][j-1] = true;
                ans = ans || solve(word , board , idx + 1 , i , j-1 , vis);
                vis[i][j-1] = false;
            }
        }

        //right
        if(j+1 < board[0].size() && !vis[i][j+1]){
            if(board[i][j+1] == word[idx]){
                vis[i][j+1] = true;
                ans = ans || solve(word , board , idx + 1 , i , j+1 , vis);
                vis[i][j+1] = false;
            }
        }

        return ans;

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