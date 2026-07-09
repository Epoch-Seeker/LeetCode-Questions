class Solution {
public:
    int solve(vector<vector<int>>& mat , int i , int j , int m , int n ,vector<vector<int>>& dp){
        
        vector<pair<int , int>> dir = {{-1,0} , {1,0} , {0 , -1} , {0 , 1}};
        int ans = 1;
        // cout<<mat[i][j]<<" ";

        if(dp[i][j] != -1)return dp[i][j];

        for(auto dr : dir){
            int x = i + dr.first;
            int y = j + dr.second;

            if(x >= 0 && y >= 0 && x <m && y < n){
                if(mat[x][y] > mat[i][j]){
                    
                    ans = max (ans , 1 +solve(mat , x , y , m , n , dp));
                    // cout<<endl;
                }
            }
        } 
        // cout<<endl;
        return dp[i][j] = ans;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m , vector<int> (n , -1));

        int ans = 1;

        for(int i=0;i< m ;i++){
            for(int j = 0;j<n ; j++){
                ans = max(ans , solve(matrix , i , j , m , n , dp));
            }
        }

        return ans;
    }
};