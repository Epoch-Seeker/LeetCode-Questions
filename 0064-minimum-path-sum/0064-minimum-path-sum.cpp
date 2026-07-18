class Solution {
public:
    int solve(vector<vector<int>>& grid , int m , int n){
        vector<int> cur(n+1 , INT_MAX);
        vector<int> down(n+1 , INT_MAX);
        
        cur[n-1] = grid[m-1][n-1];

        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1; j>=0 ; j--){ 
                int ans = min(down[j] , cur[j+1]);
                if(ans != INT_MAX)cur[j] = grid[i][j] + ans;
            }
            down = cur;
        }

        return down[0];
 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid  , m , n );
    }
};