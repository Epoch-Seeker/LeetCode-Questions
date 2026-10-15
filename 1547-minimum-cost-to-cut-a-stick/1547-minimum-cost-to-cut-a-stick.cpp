class Solution {
public:
    int solve(int i , int j , vector<int>& cuts , vector<vector<int>>& dp){
        if(i+1 == j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int ans = INT_MAX;

        for(int k= i+1 ; k < j ; k++){
            ans = min(ans , (cuts[j] - cuts[i]) + solve(i ,k , cuts , dp) + solve(k , j , cuts , dp));
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int m = cuts.size();

        vector<vector<int>> dp(m+1 , vector<int>(m+1 , -1));
        return solve( 0 , m-1 , cuts , dp);
    }
};