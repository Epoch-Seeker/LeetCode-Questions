class Solution {
public:
    bool solve(string& s , int i , int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int strt = 0;
        int i = 0;
        
        int maxlen = 1;

        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1< n ; i++){
                int j = i + len - 1;

                if(solve(s , i , j) && len > maxlen){
                    maxlen = len;
                    strt = i;
                }
            }
        }

        return s.substr(strt , maxlen);
    }
};