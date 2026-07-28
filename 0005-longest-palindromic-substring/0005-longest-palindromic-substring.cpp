class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int strt = 0;
        int i = 0;
        vector<vector<bool>> dp(n, vector<bool>(n , false));
        int maxlen = 1;

        for(int i=0;i<n ; i++){
            dp[i][i] = true;
        }

        for(int i=0;i<n-1 ; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]=true;
                if(maxlen == 1){
                    strt = i;
                    maxlen = 2;
                }
            }
        }


        for(int len =  3 ; len <= n ; len++){
            for(int i = 0 ; i + len -1 < n; i++){
                int j = i + len - 1;

                if(s[i] == s[j] && dp[i+1][j-1] ){
                    dp[i][j] = true;
                    if(len > maxlen){
                        maxlen = len;
                        strt = i;
                    }
                }

            }
        }

        return s.substr(strt , maxlen);
    }
};