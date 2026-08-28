class Solution {
public:
    // int solve(int m , int n , vector<vector<int>>& dp){

        
    //     if(m <= 0|| n <= 0)return 0;
    //     if(m == 1 && n == 1)return 1;

    //     if(dp[m][n] != -1)return dp[m][n];

    //     return 
    // }
    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
        // vector<int> up(n+1 , 0);
        vector<int> curr(n+1 , 0);
        curr[1] = 1;

        for(int i =1 ; i<= m ; i++){
            for(int j=1;j<= n ; j++){
                if(i == 1 && j== 1)continue;
                curr[j] = curr[j] +curr[j-1] ;
            }
            
        }

        return curr[n];
         
    }
};